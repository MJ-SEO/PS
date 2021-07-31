#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

vector<int> graph[1005];
int visit[1005];

int dfs(int n){
	if(visit[n] == 1) return 0;	
//	cout << "DEUBG " << n << "\n";
	for(int i=0; i<graph[n].size(); i++){
		visit[n] = 1;
		dfs(graph[n][i]);
	}
	return 1;
}

int getcycle(int n){
	int cycle = 0;
	for(int i=1; i<=n; i++){
		cycle += dfs(i);
	}
	return cycle;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for(int i=0; i<n; i++){
		int n_vertex;
		cin >> n_vertex;
		
		for(int i=1; i<=n_vertex; i++){
			int obj;
			cin >> obj;
			graph[i].push_back(obj);	
		}
		
		cout << getcycle(n_vertex) << "\n";
		
		memset(visit, 0, sizeof(visit));
		for(int i=1; i<=n_vertex; i++){
			graph[i].clear();
		}		
	}

	return 0;
}

