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

queue<pair<int, int>> que;

void BFS(int x, int y){
	que.push({x, y});
	while(!que.empty()){
		pair<int, int> curr = que.front(); que.pop();
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

	cin >> w >> h;	
		
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			cin >> map[i][j];
		}
	}

	return 0;
}
