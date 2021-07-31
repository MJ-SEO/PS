#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

vector<int> graph[100005];
int visit[100005];
int isteam;
int zzz;

int dfs(int n){
	// 여기서 팅긴다.
	if(visit[n] == 1) return 0;	
//	cout << "DEUBG " << n << "\n";
	for(int i=0; i<graph[n].size(); i++){
		visit[n] = 1;
		dfs(graph[n][i]);
		isteam++;	
		if(graph[n][i] == n) zzz = isteam;
	}
	cout << "[DEBUG] " << n << " " << isteam << " " << zzz << "\n";
	return isteam;
}

int getteams(int n){
	int team = 0;
	for(int i=1; i<=n; i++){
		team += dfs(i);
		isteam = 0;
	}
	return team;
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
		
		cout << n_vertex - getteams(n_vertex) << "\n";
		
		memset(visit, 0, sizeof(visit));
		for(int i=1; i<=n_vertex; i++){
			graph[i].clear();
		}		
	}

	return 0;
}

