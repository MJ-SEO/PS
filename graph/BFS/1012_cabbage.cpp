#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

#define X first
#define Y second

int map[51][51];
int visited[51][51]; 
int dx[4] = { 0, 0, 1, -1};
int dy[4] = { 1, -1, 0, 0};

void clean_map(){
	for(int i=0; i<51; i++){
		for(int j=0; j<51; j++){
			map[i][j] = 0;
			visited[i][j] = 0;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;

	for(int i=0; i<T; i++){
		clean_map();
		int n_worms = 0;
		int M, N, K;
		cin >> M >> N >> K;
		for(int j=0; j<K; j++){
			int X, Y;
			cin >> X >> Y;
			map[X][Y] = 1;
		}

		queue<pair<int, int>> que;
		
		for(int k=0; k<M; k++){
			for(int l=0; l<N; l++){
				if(map[k][l] == 0 || visited[k][l] == 1) continue;
				n_worms++;
//				cout << "DEBUG " << k << " " << l << "\n";

				que.push({k, l});
				visited[k][l] = 1;

				while(!que.empty()){
					pair<int, int> cur = que.front(); que.pop();

//					cout << "DEBUG2222 " << cur.first << " " << cur.second << "\n";
					for(int m=0; m<4; m++){
						int nx = cur.first + dx[m];
						int ny = cur.second + dy[m];

						if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
						if(visited[nx][ny] == 1) continue;
						if(map[nx][ny] == 0) continue; 

						que.push({nx, ny});
						visited[nx][ny] = 1;
					}
				}
			}
		}

		cout << n_worms << "\n";
	}
	
	return 0;
}
