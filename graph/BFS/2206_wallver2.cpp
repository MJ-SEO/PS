#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int N, M;
int map[1005][1005];
int dist[1005][1005][2];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

queue<tuple<int, int, int>> que;

int bfs(){
	while(!que.empty()){
		int x, y, flag;
		tie(x, y, flag) = que.front(); que.pop();
		
		if(x == N-1 && y == M-1) return dist[x][y][flag];

		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nw = flag;

			if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if(dist[nx][ny][nw] > 0) continue;
			if(map[nx][ny] == 1){
				if(nw == 1) continue;
				else nw = 1;
			}

			que.push(make_tuple(nx, ny, nw));
			dist[nx][ny][nw] = dist[x][y][flag] + 1;		
		}
	}
	
	return -1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for(int i=0; i<N; i++){
		string temp;
		cin >> temp;
		for(int j=0; j<M; j++){
			map[i][j] = temp[j] - '0';
 		}
	}

	que.push(make_tuple(0,0,0));
	dist[0][0][0] = 1;
	cout << bfs();

	return 0;
}