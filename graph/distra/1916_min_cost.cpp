#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

using pii =  pair<int,int>;
int n, m;
int d[1005];
const int INF = 1e8+10;
vector<pii> graph[1005];
int map[1005][1005];

int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
	cin >> n >> m;
	
	fill(d, d+n+1, INF);


	for(int i=0; i<m; i++){
		int start, end, cost;
		cin >> start >> end >> cost;
		graph[start].push_back({cost,end});	
	}

	cout << "==============Shape of graph==============\n";
	for(int i=1; i<=n; i++){
		cout << i << ": ";
		for(int j=0; j<graph[i].size(); j++){
			cout << "(" << graph[i][j].first << "," << graph[i][j].second << ")" << "->";
		}
		cout << "\n";
	}
	cout << "==========================================\n";


	int begin, dest;
	cin >> begin >> dest;
	
	d[begin] = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(begin);

	while(!pq.empty()){
		int curr = pq.top(); pq.pop();
		//if(d[idx] != dist) continue;
		for(int i=0; i < graph[curr].size(); i++){
			if(d[graph[curr][i].second] > d[curr] + graph[curr][i].first){
				d[graph[curr][i].second] = d[curr] + graph[curr][i].first;
				pq.push(graph[curr][i].second);
			}		
		}
	}

	cout << d[dest] << "\n";
	
        return 0;
}

