#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dt = 0;

vector<int> graph[10005];
vector<int> trans_graph[10005];
int source[10005];
int fin[10005];
int color[10005];


void DFS(int n){
//	cout << "DEBUG in DFS " << graph[n][m].node << " " << graph[n][m].color << "\n";
	color[n] = 1;
	dt++;
	source[n] = dt;
	for(int i=0; i<graph[n].size(); i++){
		if(color[graph[n][i]] == 0){
			DFS(graph[n][i]);
		}
	}
	color[n] = 2;
	dt++;
	fin[n] = dt;
}	

void transpose(int nodes){
	for(int i=0; i<nodes; i++){
		for(int j=0; j<nodes; j++){
			
		}
	}
}

int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
	int v, e;
	cin >> v >> e;
	
	for(int i=0; i<e; i++){
		int start, end;
		cin >> start >> end;
		graph[start].push_back(end);
		trans_graph[end].push_back(start);
	}

	for(int i=1; i<=v; i++){
		for(int j=0; j<graph[i].size(); j++){
			if(color[i] == 0){
				DFS(i);      
			}
		}
	}

	for(int i=1; i<=v; i++){
		cout << "[DEBUG] node: " << i << " " << source[i] << " " << fin[i] << "\n";
	}

	transpose(v);

	
	return 0;
}

