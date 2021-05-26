#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

using pii =  pair<int,int>;
int v, e, st;
int d[20005];
const int INF = 1e9+10;
vector<pii> arr[20005];

int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
	cin >> v >> e >> st;
	
	fill(d, d+v+1, INF);
	
	for(int i=0; i<e; i++){
		int start, obj, dist;
		cin >> start >> obj >> dist;
		arr[start].push_back({dist, obj}); // start부분이 겹치지 않는가?

//		cout << "DEBUG : " << start << " " << obj << " " << dist << "\n";
	}	
	
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	d[st] = 0;
	pq.push({d[st], st});

	while(!pq.empty()){
		auto cur = pq.top(); pq.pop();
		int dist = cur.first;
		int idx = cur.second;
		if(d[idx] != dist) continue;
		for(auto e : arr[idx]){
			int cost = e.first, nidx = e.second;
//			cout << "[DEBUG] cost, nidx: " << cost << " " << nidx << "\n";
			if(d[nidx] > dist+cost){
				d[nidx] = dist+cost;
				pq.push({d[nidx], nidx});
			}
		}
	}

	for(int i=1; i<=v ; i++){
		if(d[i] == INF) cout << "INF\n";
		else cout << d[i] << "\n";
	}	
        return 0;
}

