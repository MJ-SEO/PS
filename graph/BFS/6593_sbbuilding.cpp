#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<tuple>

using namespace std;

#define X first
#define Y second

char map[31][31][31];
int dist[31][31][31]; 
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};


void clean_maps(){
	for(int h=0; h<31; h++){
		for(int r=0; r<31; r++){
			for(int c=0; c<31; c++){
				dist[h][r][c] = -1;			
			}
		}
	}
}

queue<tuple<int, int, int>> que;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	while(1){

	int height, row, col;
	cin >> height >> row >> col;
	if(height == 0 && row == 0 && col == 0) break;
	int dest_h, dest_r, dest_c;

	clean_maps();

	for(int h=0; h<height; h++){
		for(int r=0; r<row; r++){
			string temp;
			cin >> temp;
			for(int c=0; c<col; c++){
				map[h][r][c] = temp[c];
				if(temp[c] == 'S'){
					que.push(make_tuple(h, r, c));
					dist[h][r][c] = 0;
				}
				if(temp[c] == 'E'){
					dest_h = h;
					dest_r = r;
					dest_c = c;
				}
			}
		}
	}

	while(!que.empty()){
		tuple<int, int, int> cur = que.front(); que.pop();
		for(int i=0; i<6; i++){
			int nx = get<0>(cur) + dx[i];
			int ny = get<1>(cur) + dy[i];
			int nz = get<2>(cur) + dz[i];

			if(nx < 0 || ny < 0 || nz <0 || nx >= height || ny >= row || nz >= col) continue;
			if(dist[nx][ny][nz] >= 0) continue;
			if(map[nx][ny][nz] == '#') continue;

			que.push(make_tuple(nx, ny, nz));
			dist[nx][ny][nz] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1 ;
		}
	}


	if(dist[dest_h][dest_r][dest_c] > 0){
		cout << "Escaped in " << dist[dest_h][dest_r][dest_c] << " minute(s).\n";
	}
	else{
		cout << "Trapped!\n";
	}

/*
	for(int i=0; i<height; i++){
		for(int r=0; r<row; r++){
			for(int c=0; c<col; c++){
				cout << dist[i][r][c] << " ";
			}
			cout << "\n";
		}
	}
*/
	}

	return 0;
}
