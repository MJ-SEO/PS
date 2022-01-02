#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

vector<pair<int, int>> tree[100005];
int result[100005];
int visited[100005];
queue<int> que;

void BFS(){
	while(!que.empty()){
		int curr = que.front(); que.pop();
		for(int i=0; i<tree[curr].size(); i++){
			if(visited[tree[curr][i].first] == 1) continue;
			result[tree[curr][i].first] = result[curr] + tree[curr][i].second;
			visited[tree[curr][i].first] = 1;
			que.push(tree[curr][i].first);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for(int i=0; i<n; i++){
		int vertex;
		cin >> vertex;
		while(1){
			int v2, weight;
			cin >> v2;
			if(v2 == -1) break;
			cin >> weight;
			tree[vertex].push_back({v2, weight});
		}
	}
	
	int maxx = 0;
	int nnn = 0;

	visited[1] = 1;
	que.push(1);
	BFS();

	for(int i=1; i<=n; i++){
		if(result[i] > maxx){
			maxx = max(maxx, result[i]);
			nnn = i;
		}
	}

	memset(visited, 0, sizeof(visited));
	memset(result, 0, sizeof(result));

	visited[nnn] = 1;
	que.push(nnn);
	BFS();
	
	maxx = 0;
	for(int i=1; i<=n; i++){
		if(result[i] > maxx){
			maxx = max(maxx, result[i]);
		}
	}

	cout << maxx << "\n";
	return 0;
}
