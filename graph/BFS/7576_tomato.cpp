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
int map[1000][1000];
int visited[1000][1000];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	queue<pair<int,int>> que;

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &map[i][j]);
			if(map[i][j] == 1){
				que.push({i,j});			
			}
			if(map[i][j] == 0){
				visited[i][j] = -1;
			}
		}
	}
	
	while(!que.empty()){
		pair<int,int> cur = que.front(); que.pop();
//		if(cur.X == n-1 && cur.Y == m-1) break;
//		cout << '(' << cur.X << ", " << cur.Y << ") -> ";
		for(int i=0; i<4; i++){
			int x = cur.X + dx[i];
			int y = cur.Y + dy[i];	
			if(x < 0 || x >= m || y < 0 || y >= n) continue;
			if(visited[x][y] >= 0) continue;
			que.push({x,y});
			visited[x][y] = visited[cur.X][cur.Y] + 1;
		}
	}
	int nn = 0;


	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(visited[i][j] == -1){
				printf("-1\n");
				return 0;
			}
			nn = max(nn, visited[i][j]);
		}
	}     

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}     
	cout << "\n";
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}     

	printf("%d\n", nn);
		
	return 0;
}
