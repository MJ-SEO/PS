#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n;
int map[105][105];
int dist[105][105];
int visited[105][105];
int s_visited[105][105];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

#define X first
#define Y second

int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
	cin >> n;
	int result = 100000;
	queue<pair<int,int>> que;
	queue<pair<int,int>> q2;

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> map[i][j];
		}
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(map[i][j] == 0 || s_visited[i][j] == 1) continue;
			que.push({i,j});
			q2.push({i,j});

			cout << "[DEBUG] push: " << i << " " << j << "\n";
			visited[i][j] = 1;
			s_visited[i][j] = 1;

			while(!q2.empty()){
				pair<int, int> cur = q2.front(); q2.pop();
			
				for(int k=0; k<4; k++){
					int x = cur.X + dx[k];
					int y = cur.Y + dy[k];
					
					if(x<0 || x>=n || y<0 || y>=n) continue;
					if(s_visited[x][y]) continue;
					if(map[x][y] == 0) continue;
					
					q2.push({x,y});
					s_visited[x][y] = 1;
				}
			}

			while(!que.empty()){
				pair<int, int> cur = que.front(); que.pop();
			
				for(int k=0; k<4; k++){
					int x = cur.X + dx[k];
					int y = cur.Y + dy[k];
					
					if(x<0 || x>=n || y<0 || y>=n) continue;
					if(visited[x][y]) continue;
					if(map[x][y] == 0){
						dist[x][y] = dist[cur.X][cur.Y]+1;
					}
					if(map[x][y] == 1 &&  

					que.push({x,y});
					visited[x][y] = 1;
				}

			}
			cout << "==========S_visited===========\n";	
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					cout << s_visited[i][j] << " ";
				}
				cout << "\n";
			}

			cout << "==============================\n\n";
			
			cout << "=============dist=============\n";	

			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					cout << dist[i][j] << " ";
				}
				cout << "\n";
			}
			cout << "==============================\n\n";

			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					dist[i][j] = 0;
				}
			}
			
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					visited[i][j] = 0;
				}
			}

		}
	}


	

        return 0;
}
