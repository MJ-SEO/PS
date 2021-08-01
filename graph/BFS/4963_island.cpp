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
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1};
int w, h;

queue<pair<int, int>> que;

void BFS(int x, int y){
	que.push({x, y});
	while(!que.empty()){
		pair<int, int> curr = que.front(); que.pop();
//		cout << "[DEBUG] " << curr.X << " " << curr.Y << "\n";
		for(int i=0; i<8; i++){
			int cur_x = curr.X + dx[i]; 
			int cur_y = curr.Y + dy[i];
			if(cur_x < 0 || cur_x >= h || cur_y < 0 || cur_y >=w) continue;
			if(map[cur_x][cur_y] == 0) continue;	
			if(visited[cur_x][cur_y]) continue;	
			visited[cur_x][cur_y] = 1;
			que.push({cur_x, cur_y});
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);


	while(1){
		int island = 0;

		cin >> w >> h;	
		if(w == 0 && h ==0) break;
		
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				cin >> map[i][j];
			}
		}
			
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				if(map[i][j] == 1){
					if(visited[i][j] == 0){
						BFS(i, j);
						island++;
					}
				}
			}
		}

		memset(visited, 0, sizeof(visited));
		
		cout << island << "\n";
	}
}
