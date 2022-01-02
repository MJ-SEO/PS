#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dt = 0;

int source[10005];
int color[10005];
pair<int, int> fin[10005]; 
int disjoint_set = 0;
int flag;
vector<int> result[10005];

bool compare(vector<int> &a, vector<int> &b){
	return a[0] < b[0];	
}

bool DFS(int n, vector<int> g[], int tr){
	if(color[n] == 2) {
		result[disjoint_set].push_back(20000);
		return false;
	}
	if(tr == 1)
		result[disjoint_set].push_back(n);

	color[n] = 1;
	dt++;
	source[n] = dt;
	for(int i=0; i<g[n].size(); i++){
		if(color[g[n][i]] == 0){
			DFS(g[n][i], g, tr);
		}
	}
	color[n] = 2;
	dt++;
	fin[n].first = dt;
	fin[n].second = n;
	return true;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> graph[10005];
	vector<int> trans_graph[10005];
	
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
				DFS(i, graph, 0);      
			}
		}
	}
	sort(fin+1, fin+v+1, greater<pair<int,int>>());
	for(int i=0; i<=v; i++)
		color[i] = 0;

	int t[v+1];
	for(int i=1; i<=v; i++) t[i] = fin[i].second;

	for(int i=1; i<=v; i++){	
		DFS(t[i], trans_graph, 1);
		disjoint_set++;
	}

	int zz=0;
	for(int i=0; i<v; i++){
		sort(result[i].begin(), result[i].end());
		if(result[i][0] > 0 && result[i][0] < 19999){
			zz++;		
		}
	}
	sort(result, result+v, compare);

	cout << zz << "\n";
	for(int i=0; i<zz; i++){
		for(int j=0; j<result[i].size(); j++){
			cout << result[i][j] << " ";
		}
		cout << "-1 \n";
	}

	return 0;

}
