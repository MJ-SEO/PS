#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int map[10][10];
int dup_map[10][10];
vector<pair<int, int>> cctvs;
int space;
int number_of_camera;
int answer;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};


int fill_space(int x, int y, int dir, int option){
	int ad_dir = dir % 4;
	int cnt = 0;

	while(1){
		x = x + dx[ad_dir];
		y = y + dy[ad_dir];

		if(x < 0 || y < 0 || x >= N || y >= M) break;
		if(map[x][y] == 6) break;	// wall
		if(map[x][y] > 0 && map[x][y] < 6) continue;	// another cctv
		
		if(option){					// fill_space
			if(map[x][y] == 0){
				if(dup_map[x][y] == 0){
					dup_map[x][y] = 7;		
					cnt++;
				}
				else{				// alredy watched
					dup_map[x][y]++;
				}
			}
		}
		else{						// free_space
			if(dup_map[x][y] == 7){
				dup_map[x][y] = 0;
			}
			else{
				dup_map[x][y]--;
			}
		}
	}

	return cnt;
}

int watch(int cam_idx, int dir, int option){
	int x = cctvs[cam_idx].first;
	int y = cctvs[cam_idx].second;
	int space_cnt = 0;

	if(map[x][y] == 1){
		space_cnt += fill_space(x, y, dir, option);
	}
	else if(map[x][y] == 2){
		space_cnt += fill_space(x, y, dir, option);
		space_cnt += fill_space(x, y, dir+2, option);
	}
	else if(map[x][y] == 3){
		space_cnt += fill_space(x, y, dir, option);
		space_cnt += fill_space(x, y, dir+1, option);
	}
	else if (map[x][y] == 4){
		space_cnt += fill_space(x, y, dir, option);
		space_cnt += fill_space(x, y, dir+1, option);
		space_cnt += fill_space(x, y, dir+2, option);
	}
	else{
		space_cnt += fill_space(x, y, dir, option);
		space_cnt += fill_space(x, y, dir+1, option);
		space_cnt += fill_space(x, y, dir+2, option);
		space_cnt += fill_space(x, y, dir+3, option);
	}

	return space_cnt;
}


void solve(int k, int camera){

	if(k == number_of_camera){
		answer = min(answer, space);
		return;
	}

	for(int i=camera; i<cctvs.size(); i++){	
		for(int dir=0; dir<4; dir++){
			int temp = watch(i, dir, 1);
			space -= temp;
//			cout << "DEBUG " << i << " " << dir << " " << temp << "\n";
			solve(k+1, i+1);
			space += temp;
			watch(i, dir, 0); // watch의 역
		}
	}
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	space = N*M;
	answer = N*M;
	int walls = 0;

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> map[i][j];
			if(map[i][j] > 0 && map[i][j] <= 5){
				cctvs.push_back({i, j});
				number_of_camera++;
			}
			if(map[i][j] == 6){
				walls++;
			}
		}
	}

	space -= (number_of_camera + walls);

	solve(0, 0);

	cout << answer << "\n";

	return 0;
}

