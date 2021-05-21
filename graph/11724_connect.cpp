#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

vector<int> graph[1005];
int visited[1005];
queue<int> que;

void BFS(int n){
	while(!que.empty()){
		int temp = que.front(); que.pop();
		for(int i=0; i < graph[temp].size(); i++){
			if(visited[graph[temp][i]] == 0){
				que.push(graph[temp][i]);
				visited[graph[temp][i]] = 1;
			}	
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int cc = 0;
	int check = 0;
	int n, m;
	cin >> n >> m;


	for(int i=0; i<m; i++){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	

	for(int i=1; i<=n; i++){
		if(visited[i] == 0){
			que.push(i);
			visited[i] = 1;
			BFS(i);
			cc++;
		}
	}


	cout << cc << "\n";
	return 0;
}

