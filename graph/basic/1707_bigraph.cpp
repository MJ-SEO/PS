#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

vector<int> graph[20005];
int visited[20005];
queue<int> que;

void BFS(){
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

	int k;
	cin >> n;

	for(int i=0; i<k; i++){
		int v, e;
		cin >> v >> e;
		for(int j=0; j<e; j++){
			int st, ed;
			cin >> st >> ed;
			graph[st].push_back(ed);
			graph[ed].push_back(st);
		}
		
		// vigraph 판별
		
		// 그래프 초기화
	}
	return 0;
}

