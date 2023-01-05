#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

#define X first
#define Y second

int K, N, M;
int map[201][201];
int dist[201][201][31];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1}

queue<tuple<int, int, int>> que;

int bfs(){
	while(!que.empty()){
		int x, y, flag;
		tie(x, y, flag) = que.front(); que.pop();

		if(x == N-1 && y == M-1) return dist[x][y][flag] - 1;
		
		for(int i=0; i<4; i++){
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			int nh = flag;

			if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
			if(map[nx][ny] == 1) nw++;
			if(nh > K || dist[nx][ny][nw] > 0) continue;

			que.push(make_tuple(nx, ny, nw));
			dist[nx][ny][nw] = dist[x][y][flag] + 1;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> K >> N >> M;

	for(int i=0; i<W; i++){
		for(int j=0; j<H; j++){
			cin >> map[i][j];
		}
	}

	que.push(make_tuple(0,0,0));
	dist[0][0][0] = 1;

	cout << bfs();

	return 0;
}

