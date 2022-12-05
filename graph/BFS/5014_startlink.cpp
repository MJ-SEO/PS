#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int F, S, G, U, D;
int map[1000005];
int visited[1000005];

queue<int> que;

void bfs(){
	while(!que.empty()){
		int cur = que.front(); que.pop();	
		for(int nxt : {cur + U, cur - D}){
			if(nxt <= 0 || nxt > F) continue;
			if(visited[nxt] >= 0) continue;

			que.push(nxt);
			visited[nxt] = visited[cur] + 1;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> F >> S >> G >> U >> D;

	for(int i=0; i<=F; i++) visited[i] = -1;

	que.push(S);
	visited[S] = 0;
	bfs();
	
	if(visited[G] != -1) cout << visited[G] << "\n";
	else cout << "use the stairs\n";
	
	return 0;
}

