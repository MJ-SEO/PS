#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dt = 0;

vector<int> graph[10005];
vector<int> trans_graph[10005];
int source[10005];
pair<int, int> fin[10005]; // pair?
int color[10005];
int disjoint_set = 0;
int flag;
vector<int> result[10005];

bool DFS(int n, vector<int> g[]){
	if(color[n] == 2) return false;
	cout << n << "->";
	result[disjoint_set].push_back(n);
	color[n] = 1;
	dt++;
	source[n] = dt;
	for(int i=0; i<g[n].size(); i++){
		if(color[g[n][i]] == 0){
			DFS(g[n][i], g);
		}
	}
	color[n] = 2;
	dt++;
	fin[n].first = dt;
	fin[n].second = n;
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
				DFS(i, graph);      
			}
		}
	}
	
	for(int i=1; i<=v; i++){
		cout << i << ": ";
		for(int j=0; j<graph[i].size(); j++){
			cout << "->" << graph[i][j];
		}
		cout << "\n";
	}

	for(int i=1; i<=v; i++){
		cout << "[DEBUG] node: " << fin[i].second << " (" << source[i] << "," << fin[i].first << ")\n";
	}


	for(int i=1; i<=v; i++){
		cout << i << ": ";
		for(int j=0; j<trans_graph[i].size(); j++){
			cout << "->" << trans_graph[i][j];
		}
		cout << "\n";
	}

	sort(fin+1, fin+v+1, greater<pair<int,int>>());
	for(int i=0; i<=v; i++)
		color[i] = 0;


	for(int i=1; i<=v; i++){
		cout << "[DEBUG] node: " << fin[i].second << " (" << source[i] << "," << fin[i].first << ")\n";
	}

	
	for(int i=1; i<=v; i++){	
		cout <<"durldurl " << i << " :";
		DFS(fin[i].second, trans_graph);
		disjoint_set++;
		cout << "\n";
	}

	for(int i=0; i<=v; i++){
		sort(result[i].begin(), result[i].end());
	}


	cout << "\n";
	for(int i=0; i<=v; i++){
		cout << i << ": ";
		for(int j=0; j<result[i].size(); j++){
			cout << result[i][j] << " ";
		}
		cout << "-1 \n";
	}

	return 0;
}

