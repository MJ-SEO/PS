#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

char map[11][11];
int mapc[11][11];

int N, M;

int dx[4] = {-1, 1, 0, 0};	// 상하좌우
int dy[4] = {0, 0, -1, 1};	

queue<pair<int, int>> red_que;
queue<pair<int, int>> blue_que;

int red_in = 0;
int blue_in = 0; 
int turn = 0;
int samed = 0;

pair<int, int> rolling(char color, int direction, int X, int Y, int* t){	// 1.red 2.blue
	int nx = X;
	int ny = Y;
	int flag = 0;

	while(1){
		nx = nx + dx[direction];
		ny = ny + dy[direction];
//		cout << "NX NY " << nx << " " << ny << " " << "[" << map[nx][ny] << "]" <<  "\n";

		if(map[nx][ny] == '#') {
			nx = nx - dx[direction];
			ny = ny - dy[direction];
			break;
		}
		if(map[nx][ny] == 'O') {
			if(color == 'R'){
				red_in = 1;
				*t = direction;
				break;
			}
			else{
				blue_in = 1;
				*t = direction;
				break;
			}
		}

		if(color == 'R'){
			if(map[nx][ny] == 'B') flag = 1;
		}

		if(color == 'B'){
			if(map[nx][ny] == 'R') flag = 1;
		}
	}
	
	if(flag == 1){
		nx = nx - dx[direction];
		ny = ny - dy[direction];
	}

	pair<int, int> temp = make_pair(nx, ny);
	return temp;
}

void BFS(){
	while(red_in != 1){
		if(blue_in == 1) break;
		pair<int ,int> cur_red, cur_blue;
	
		cur_red = red_que.front(); red_que.pop();
		cur_blue = blue_que.front(); blue_que.pop();
		
		int r_count = 0;
		int b_count = 0;

		for(int i=0; i<4; i++){	// 상하좌우
			pair<int, int> nx_red;
			pair<int, int> nx_blue;
			
			int rt=100000;
			int bt=200000;

			//cout << "[CURR RED] " << cur_red.first << " " << cur_red.second << "\n";
			//cout << "[CURR BLUE] " << cur_blue.first << " " << cur_blue.second << "\n";
			nx_red = rolling('R', i, cur_red.first, cur_red.second, &rt);
			nx_blue = rolling('B', i, cur_blue.first, cur_blue.second, &bt);
			
	//		cout << "DEBUG " << red_in << " " << blue_in << "\n";
			if(blue_in == 1 && red_in == 1){
	//			cout << "BTRT " << rt << " " << bt << "\n";
				if(bt != rt)  
					blue_in = 0; 
				else
					samed = 1;
			}

			//cout << "[NEXT RED] " << nx_red.first << " " << nx_red.second << "\n";
			//cout << "[CURR BLUE] " << cur_blue.first << " " << cur_blue.second << "\n";

			if(nx_red.first == cur_red.first && nx_red.second == cur_red.second){
				r_count++;	
			}else{
				red_que.push(nx_red);
				cout << "[RED] " << nx_red.first << " " << nx_red.second << " [" << turn << "]\n";
				mapc[nx_red.first][nx_red.second] = mapc[cur_red.first][cur_red.second] + 1;
				turn = max(mapc[nx_red.first][nx_red.second], turn);
			}

			if(nx_blue.first == cur_blue.first && nx_blue.second == cur_blue.second){
				b_count++;
			}
			else{
				blue_que.push(nx_blue);
	//			cout << "[BLUE] " << nx_blue.first << " " << nx_blue.second << " [" << turn << "]\n";
			}

			if(r_count == 4) red_que.push({cur_red.first, cur_red.second});
			if(b_count == 4) blue_que.push({cur_blue.first, cur_blue.second});
		}
	
		if(turn > 10) break;	
	}	
}

void show_map(){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	int ox, oy;

	for(int i=0; i<N; i++){
		string temp;
		cin >> temp;

		for(int j=0; j<M; j++){
			map[i][j] = temp[j];
			if(temp[j] == 'B'){
				blue_que.push({i,j});
			}
			if(temp[j] == 'R'){
				red_que.push({i,j});
			}
			if(temp[j] == 'O'){
				ox = i;
				oy = j;
			}
		}
	}

	show_map();

	BFS();
	
	cout << turn << " " << red_in << " " << blue_in << " " << mapc[ox][oy] << "\n";

	if((blue_in == 1 && red_in == 0) || turn > 10 || samed){
		cout << "-1" << "\n";
	}
	else{
		cout << mapc[ox][oy] << "\n";
	}
	return 0;
}

