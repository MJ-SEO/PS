#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> graph[500001];
int visited[500001];

void show_graph(){
	for(int i=0; i<N; i++){
		cout << "[" << i << "]  ";
		
		for(int j=0; j<graph[i].size(); j++){
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}
}

int BFS(){
	queue<int> que;
	que.push(0);
	visited[0] = 1;
	
	while(!que.empty()){
			int curr = que.front(); que.pop();
			if(curr == turn) return 1;

			for(int i=0; i < graph[curr].size(); i++){
				if(visited[graph[curr][i]]) continue;
				que.push(graph[curr][i]);
				visited[graph[curr][i]] = 1;
			}
	}

	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int flag = 0;
	cin >> N >> M;

	for(int i=0; i<M; i++){
		int start, dest;
		cin >> start >> dest;
		graph[start].push_back(dest);
		graph[dest].push_back(start); // No direction.
		
		if(i >= 2){
			if(BFS()){

			}
			else{

			}
		}
	}
	
	int turn;
	for(turn=0; turn<N; turn++){
		if(BFS(turn)){
			flag = 1;
			break;
		}
		else{
			for(int i=0; i<N; i++){
				visited[i] = 0;
			}
		}
	}

	if(flag == 0) cout << 0 << "\n";
	else cout << turn + 1 << "\n";
	
	return 0;
}

