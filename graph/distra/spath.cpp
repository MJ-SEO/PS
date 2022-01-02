#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

using pii =  pair<int,int>;
int n, m;
int d[1005];
int pre[1005];
const int INF = 1e9+10;
vector<pii> arr[1005];

int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
	cin >> n >> m;
	
	fill(d, d+n+1, INF);
	
	for(int i=0; i<m; i++){
		int start, obj, dist;
		cin >> start >> obj >> dist;
		arr[start].push_back({dist, obj});

	//	cout << "DEBUG : " << start << " " << obj << " " << dist << "\n";
	}	
	
	int start, end;
	cin >> start >> end;

	priority_queue<pii, vector<pii>, greater<pii> > pq;
	d[start] = 0;
	pq.push({d[start], start});

	while(!pq.empty()){
		auto cur = pq.top(); pq.pop();
		int dist = cur.first;
		int idx = cur.second;
		if(d[idx] != dist) continue;
		for(auto e : arr[idx]){
			int cost = e.first, nidx = e.second;
//			cout << "[DEBUG] cost, nidx: " << cost << " " << nidx << "\n";
			if(d[nidx] > dist+cost){

				pre[nidx] = idx;
				d[nidx] = dist+cost;
				pq.push({d[nidx], nidx});
			}
		}
	}

	stack<int> path;
	int temp = end;
	path.push(temp);	
//	cout << "path : " << path.top() << " ";


	while(1){
		if(temp == start) break;
		temp = pre[temp];
		path.push(temp);
//		cout << temp << " ";
	}	
//	cout << "\n";

	int d_count=path.size();	
//	reverse(path.begin(), path.end());

	cout << d[end] << "\n";
	cout << d_count << "\n";
	for(int i=0; i<d_count ; i++){
		cout << path.top() << " ";
		path.pop();		
	}	
        return 0;
}

