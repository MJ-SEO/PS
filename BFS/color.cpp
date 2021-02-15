#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>

using namespace std;
#define X first
#define Y second


int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char map[100][100];
bool visited[100][100];
int result[100][100];

int main(){
	int n;
	scanf("%d", &n);
	char buf[10];

	scanf("%c", buf);
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%c", &map[i][j]);
		}
		scanf("%c", buf);
	}

	queue<pair<int,int>> que;  // R = 0, G = 1, B = 2
	int ans = 0;
	int ans2 = 0;
	

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(visited[i][j] == 1) continue;
			visited[i][j] = 1;
			que.push({i,j});

			while(!que.empty()){	
				pair<int,int> cur = que.front(); que.pop();
				for(int k=0; k<4; k++){
					int x = cur.X + dx[k];
					int y = cur.Y + dy[k];
					char rgb = map[cur.X][cur.Y];
					
					if(x < 0 || x >= n || y < 0 || y >= n) continue;
					if(visited[x][y] == 1 || map[x][y] != rgb) continue;
					que.push({x,y});
					visited[x][y] = 1;
				}
			}
			ans++;
		}
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			visited[i][j] = 0;
			if(map[i][j] == 'G'){
				map[i][j] = 'R';
			}
		}
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(visited[i][j] == 1) continue;
			visited[i][j] = 1;
			result[i][j] = 1;
			que.push({i,j});

			while(!que.empty()){	
				pair<int,int> cur = que.front(); que.pop();
				for(int k=0; k<4; k++){
					int x = cur.X + dx[k];
					int y = cur.Y + dy[k];
					char rgb = map[cur.X][cur.Y];
					
					if(x < 0 || x >= n || y < 0 || y >= n) continue;
					if(visited[x][y] == 1 || map[x][y] != rgb) continue;
					que.push({x,y});
					visited[x][y] = 1;
				}
			}
			ans2++;
		}
	}
	printf("%d %d\n", ans, ans2);	
	return 0;
}
