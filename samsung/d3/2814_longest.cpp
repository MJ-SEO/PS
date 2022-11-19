#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int longest = 1;
queue<int> que;
vector<int> graph[21];
int visited[21] = {0};


int bfs(int vertex_num){
	int length = 1;
	while(!que.empty()){
		int cur = que.front(); que.pop();
		for(int i=0; i<graph[cur].size(); i++){
			if(visited[graph[cur][i]]) continue;
			
			que.push(graph[cur][i]);
			visited[graph[cur][i]] = 1;
			length++;
		}
	}

//	cout << "DEBUG " << length << "\n";
	return length;
}

void reset_V(int n){
	for(int i=0; i<=n; i++) visited[i] = 0;
}

void reset_G(int n){
	for(int i=0; i<n; i++) {
		graph[i].clear();
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int N, M, x, y;
		cin >> N >> M;

		for(int i=0; i<M; i++){
			int x, y;
			cin >> x >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}

		for(int i=1; i<=N; i++){
			reset_V(N);
			
			que.push(i);
			visited[i] = 1;
			longest = max(bfs(i), longest);
		}

		cout << "#" << test_case << " " << longest << "\n";

		reset_G(N);
	}
	return 0;
}