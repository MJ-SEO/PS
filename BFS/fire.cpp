#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>


using namespace std;
#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char map[1005][1005];
bool visited[1005][1005];
int dist[1005][1005];
int f_dist[1005][1005];

int main(){
	int n, m;
	char buf[5];
	scanf("%d %d", &n, &m);
	scanf("%c", buf);

//	cout << "DEBUG N, M: " << n <<" "<< m << endl;

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%c", &map[i][j]);
		}
		scanf("%c", buf);
	}
/*
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
*/
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			dist[i][j] = -1;
			f_dist[i][j] = -1;
		}
	}
	

	queue<pair<int,int>> que;
	queue<pair<int,int>> f_que;

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(map[i][j] != 'F') continue;
			visited[i][j] = 1;
			f_que.push({i,j});
			f_dist[i][j] = 0;
		}
	}
	
	while(!f_que.empty()){	
		pair<int,int> cur = f_que.front(); f_que.pop();
		for(int k=0; k<4; k++){
			int x = cur.X + dx[k];
			int y = cur.Y + dy[k];

			if(x < 0 || x >= n || y < 0 || y >= m) continue;
			if(visited[x][y]) continue;
			if(map[x][y] == '#') continue;

			visited[x][y] = 1;
			f_dist[x][y] = f_dist[cur.X][cur.Y] + 1;	
			f_que.push({x,y});
		}
	}
/*
	cout << "\nf_dist table\n";
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			printf("%d ",f_dist[i][j]);
		}
		printf("\n");
	}

	cout << "============================\n\n";
*/

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			visited[i][j] = 0;
		}
	}


	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(map[i][j] != 'J') continue;
			visited[i][j] = 1;	
			dist[i][j] = 0;
			que.push({i,j});
				
			while(!que.empty()){
				pair<int,int> cur = que.front(); que.pop();
				for(int k=0; k<4; k++){
					int x = cur.X + dx[k];
					int y = cur.Y + dy[k];	
			
					if(x < 0 || x >= n || y < 0 || y >= m){
						cout << dist[cur.X][cur.Y]+1;
						return 0;
					}
					if(visited[x][y]) continue;
					if(map[x][y] == '#' || map[x][y] == 'F') continue;
					if(dist[cur.X][cur.Y]+1 >= f_dist[x][y] && f_dist[cur.X][cur.Y] != -1) continue;

					visited[x][y] = 1;
					dist[x][y] = dist[cur.X][cur.Y] + 1;
					que.push({x,y});
				}
			}
			cout << "IMPOSSIBLE\n";
		}
	}
/*
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			printf("%d ",dist[i][j]);
		}
		printf("\n");
	}
*/		
	return 0;
}
