#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int INF = 2e9 + 10;
using pii = pair<int,int>;
int N, M, X;

int d1[1005];
int d2[1005];
int temp[1005];
vector<pii> arr[1005];

int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
	int result = 0;
	cin >> N >> M >> X;

	fill(d1, d1+N+1, INF);
	fill(d2, d2+N+1, INF);
	fill(temp, temp+N+1, INF);

	while(M--){
		int start, end, time;
		cin >> start >> end >> time;
		arr[start].push_back({end, time});
	}

	priority_queue<pii, vector<pii>, greater<pii> > pq;
	d1[X] = 0;
	pq.push({X, d1[X]});

	while(!pq.empty()){
		auto cur = pq.top(); pq.pop();
		int node = cur.first;
		int dist = cur.second;
		if(d1[node] != dist) continue;
		for(auto e : arr[node]){
			int n_node = e.first;
			int cost = e.second;
			if(d1[n_node] > dist + cost){
				d1[n_node] = dist + cost;
				pq.push({n_node, d1[n_node]});
			}
		}
	}

	while(!pq.empty()){
		pq.pop();
	}

	for(int i=1; i<=N; i++){
		if(i==X) continue;
		temp[i] = 0;
		pq.push({i, temp[i]});
		while(!pq.empty()){
			auto cur = pq.top(); pq.pop();
			int node = cur.first;
			int dist = cur.second;
			if(temp[node] != dist) continue;
			for(auto e : arr[node]){
				int n_node = e.first;
				int cost = e.second;
				if(temp[n_node] > dist + cost){
					temp[n_node] = dist + cost;
					pq.push({n_node, temp[n_node]});
				}
			}
		}
		d2[i] = temp[X];
		fill(temp, temp+N+1, INF);
	}

	d2[X] = 0;

	for(int i=1; i<N+1; i++){
		result = max(result, d1[i] + d2[i]);
	}
	
	cout << result << "\n";
	return 0;
}
