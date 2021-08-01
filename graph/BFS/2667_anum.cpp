#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

#define X first
#define Y second

int map[30][30];
int visited[30][30];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n;

queue<pair<int, int>> que;

int BFS(int x, int y){
	int size = 0;
	visited[x][y] = 1;
	que.push({x, y});
	size++;

	while(!que.empty()){
		pair<int, int> curr = que.front(); que.pop();
		for(int i=0; i<4; i++){
			int cur_x = curr.X + dx[i];
			int cur_y = curr.Y + dy[i];
			if(cur_x < 0 || cur_x >= n || cur_y < 0 || cur_y >=n) continue;
			if(map[cur_x][cur_y] == 0) continue;
			if(visited[cur_x][cur_y]) continue;
			visited[cur_x][cur_y] = 1;
			que.push({cur_x, cur_y});
			size++;
		}
	}
	return size;
}


int main(){
	vector<int> dangi;
	int n_dangi = 0;

	cin >> n;

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%1d", &map[i][j]);
		}
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(map[i][j] == 1){
				if(visited[i][j] == 0){
					int size = BFS(i, j);
					dangi.push_back(size);
					n_dangi++;
				}
			}
		}
	}

	cout << n_dangi << "\n";

	sort(dangi.begin(), dangi.end());
	for(int i=0; i<dangi.size(); i++){
		cout << dangi[i] << "\n";
	}

	return 0;
}
