#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

using pii =  pair<int,int>;
int n, m;
int d[1005];
const int INF = 1e9+10;
vector<pii> graph[1005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	fill(d, d+n+1, INF);
	priority_queue<int, vector<int>, greater<int>> pq;

	for(int i=0; i<m; i++){
		int start, end, cost;
		cin >> start >> end >> cost;
		graph[start].push_back({cost,end});
	}

	int begin, dest;
	cin >> begin >> dest;

	d[begin] = 0;
	for(int i=1; i<=n; i++){
		pq.push(i);
	}

	while(!pq.empty()){
		int curr = pq.top(); pq.pop();
		for(int i=0; i<graph[curr].size(); i++){
			if(d[graph[curr][i].second] > d[curr] + graph[curr][i].first){
				d[graph[curr][i].second] = d[curr] + graph[curr][i].first;
			}
		}
	}

	cout << d[dest];
	return 0;
}

