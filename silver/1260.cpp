#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector<int> graph[1005];
int visited_dfs[1005];
int visited_bfs[1005];

stack<int> st;
queue<int> que;

void dfs(){
	while(!st.empty()){
		int curr = st.top(); st.pop();
		cout << curr << " ";
		for(int i=0; i<graph[curr].size(); i++){
			if(visited_dfs[graph[curr][i]] == 1) continue;
			dfs();
		}
	}
	cout << "\n";	

}

void bfs(){
	while(!que.empty()){
		int curr = que.front(); que.pop();
		cout << curr << " ";
		for(int i=0; i<graph[curr].size(); i++){
			if(visited_bfs[graph[curr][i]] == 1) continue;
			visited_bfs[graph[curr][i]] = 1; 
			que.push(graph[curr][i]);
		}
	}

	cout << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, v;
	cin >> n >> m >> v;

	for(int i=0; i<m; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);	
		graph[b].push_back(a);	
	}

	st.push(v);
	que.push(v);
	visited_bfs[v] = 1;
	visited_dfs[v] = 1;

	for(int i=1; i<=n; i++){
		sort(graph[i].begin(), graph[i].end());
	}

	dfs();
	bfs();
	return 0;
}

