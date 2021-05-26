#include<bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
int v,e,st;
// {cost, index}
vector<pii> adj[20005];
const int INF = 1e9+10;
int d[20005];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> v >> e >> st;
  fill(d,d+v+1,INF);
  while(e--){
    int u,v,w;
    cin >> u >> v >> w;
    adj[u].push_back({w,v});
  }
  priority_queue<pii, vector<pii>, greater<pii> > pq;
  d[st] = 0;
  pq.push({d[st],st});
  while(!pq.empty()){
    auto cur = pq.top(); pq.pop();
    int dist = cur.first, idx = cur.second;
    if(d[idx] != dist) continue;
    for(auto nxt : adj[idx]){
      int cost = nxt.first, nidx = nxt.second;
      if(d[nidx] > dist+cost){
        d[nidx] = dist+cost;
        pq.push({d[nidx],nidx});
      }
    }
  }
  for(int i = 1; i <= v; i++){
    if(d[i] == INF) cout << "INF\n";
    else cout << d[i] << "\n";
  }
}
