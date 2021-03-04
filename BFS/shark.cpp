#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define X first
#define Y second

int map[21][21];
int visited[21][21];
int dist[21][21];

int result;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int shark = 2;
	int eat = 0;
	queue<pair<int, int>> que;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> map[i][j];
			if(map[i][j] == 9){
				que.push({i,j});		
				visited[i][j] = 1;		
			}
		}
	}

	while(!que.empty()){
		pair<int,int> cur;
		cur = que.front(); que.pop();

		for(int i=0; i<4; i++){
			int x = cur.X + dx[i];
			int y = cur.Y + dy[i];

			if(x<0 || x>=n || y<0 || y>=n) continue;
			if(visited[x][y] || map[x][y] > shark) continue;
			if(map[x][y] < shark && map[x][y] > 0){
				result += dist[cur.X][cur.Y] + 1;
			}

			que.push({x,y});
			visited[x][y] = 1;
			dist[x][y] = dist[cur.X][cur.Y] + 1;
		}		
	}

	cout << "========================\n";
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	
	cout << "========================\n";

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
	cout << result << "\n";
	return 0;
}
