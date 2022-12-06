#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1}

int N;
queue<pair<int, int>> que;

void bfs(){
	while(!que.empty()){
		pair<int, int> cur = que.front(); que.pop();

		for(int i=0; i<4; i++){
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if(nx < 0 || ny < 0 || nx >= M || ny >=N) continue;
			if(visited[nx][ny] || map[nx][ny]) continue;

			que.push({nx, ny});
			visited[nx][ny] = 1;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while(T--){
		cin >> N;
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				cin >> map[i][j];
			}
		}
	}

	return 0;
}

