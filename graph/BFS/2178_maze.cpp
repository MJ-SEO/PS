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
int map[100][100];
int dist[100][100];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%1d", &map[i][j]);
			if(map[i][j] == 1){
				dist[i][j] = -1;
			}
		}
	}
	
	queue<pair<int,int>> que;
	dist[0][0] = 1;
	que.push({0,0});
	
	while(!que.empty()){
		pair<int,int> cur = que.front(); que.pop();
//		if(cur.X == n-1 && cur.Y == m-1) break;
//		cout << '(' << cur.X << ", " << cur.Y << ") -> ";
		for(int i=0; i<4; i++){
			int x = cur.X + dx[i];
			int y = cur.Y + dy[i];	
			if(x < 0 || x >= n || y < 0 || y >= m) continue;
			if(map[x][y] != 1) continue;
			if(dist[x][y] >= 0) continue;

			que.push({x,y});
			dist[x][y] = dist[cur.X][cur.Y] + 1;
		}
	}
	
	printf("%d\n", dist[n-1][m-1]);	
		
	return 0;
}
