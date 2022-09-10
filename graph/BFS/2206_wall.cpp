#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <tuple>

using namespace std;
#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int map[1001][1001];
int dist[1001][1001][2];

int main(){

	int N, M;
	cin >> N >> M;

	if(N == 1 && M == 1){
		cout << 1 << "\n";
		return 0;
	} 

	for(int i=0; i<N; i++){
		string temp;
		cin >> temp;
		for(int j=0; j<M; j++){
			map[i][j] = temp[j];
		}
	}

	queue<tuple<int, int, int>> que;
	que.push(make_tuple(0,0,0));
	dist[0][0][0] = 1;

	int flag = 0;

	while(!que.empty()){
		tuple<int, int, int> cur = que.front(); que.pop();
		for(int i=0; i<4; i++){
			int nx = get<0>(cur) + dx[i];
			int ny = get<1>(cur) + dy[i];
			int nz = get<2>(cur);

			if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if(dist[nx][ny][nz] > 0) continue;

			if(map[nx][ny] == '0'){
				que.push(make_tuple(nx, ny, nz));
				dist[nx][ny][nz] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			} 
			
			if(map[nx][ny] == '1' && nz == 0){
				que.push(make_tuple(nx, ny, 1));
				dist[nx][ny][1] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			}
		}
	}
	

	if(dist[N-1][M-1][0] == 0 && dist[N-1][M-1][1] == 0){
		cout << "-1" << "\n";
	}
	else if(dist[N-1][M-1][0] == 0){
		cout << dist[N-1][M-1][1] << "\n";
	}
	else if(dist[N-1][M-1][1] == 0){
		cout << dist[N-1][M-1][0] << "\n";
	}
	else{
		cout << min(dist[N-1][M-1][0], dist[N-1][M-1][1]) << "\n";
	}

	return 0;
}
