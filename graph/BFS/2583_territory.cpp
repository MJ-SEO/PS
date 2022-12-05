#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

queue<pair<int, int>> que;
vector<int> territories;

int M, N, K;
int map[105][105];
int visited[105][105];

int bfs(){
	int size = 0;
	while(!que.empty()){
		pair<int, int> cur = que.front(); que.pop();
		size += 1;

		for(int i=0; i<4; i++){
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if(nx < 0 || ny < 0 || nx >= M || ny >=N) continue;
			if(visited[nx][ny] || map[nx][ny]) continue;

			que.push({nx, ny});
			visited[nx][ny] = 1;
		}
	}
	return size;
}

void fill_square(int x1, int y1, int x2, int y2){
	for(int i = x1; i < x2; i++){
		for(int j = M - y2; j < M - y1; j++){
			map[j][i] = 1;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N >> K;

	for(int i=0; i<K; i++){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		fill_square(x1, y1, x2, y2);
	}

	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			if(map[i][j] == 1 || visited[i][j]) continue;

			que.push({i, j});
			visited[i][j] = 1;
			territories.push_back(bfs());
		}
	}

	sort(territories.begin(), territories.end());

	cout << territories.size() << "\n";
	for(auto e : territories) cout << e << " ";
	cout << "\n";

	return 0;
}

