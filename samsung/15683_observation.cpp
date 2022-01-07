#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int map[9][9];
int dup_map[9][9];

int N, M;
int n_cctv;
int empty_space;
int blind_spot = 1000;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};  // 상우하좌

queue<tuple<int, int, int>> que;	// x, y, cctv

void show_map(){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}

int search(int x, int y, int direction, int cctv){
	int nx;
	int ny;
	int counter = 0;

	while(1){
		nx = x + dx[direction];
		ny = y + dy[direction];

		if(map[nx][ny] == 6){
			break;
		}

		if(map[nx][ny] < 6 && map[nx][ny] != 0){
			counter--;
		}

		counter++;
	}

	return counter;
}

void BFS(){
	
	while(!que.empty()){
		tuple<int, int, int> temp = que.front(); que.pop();

		for(int i=0; i<4; i++){
			int cover = search(get<0>(temp), get<1>(temp), i, get<2>(temp));
			min(blind_spot, empty_space-cover);
		}
	}

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> map[i][j];
			if(map[i][j] == 0) empty_space++;
			if(map[i][j] < 6 && map[i][j] != 0){
				cout << "DEBUG " << map[i][j] << "\n";
				tuple<int, int, int> cctv = make_tuple(i, j, map[i][j]);
				que.push(cctv);
				//que.push(make_tuple(i, j, map[i][j]));
			}
		}
	}
	
	show_map();

	BFS();

	cout << blind_spot << "\n";

	return 0;
}

