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
int map[1000][1000];
bool visited[1000][1000];
int result[1000][1000];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &map[i][j]);
		}
	}

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}

	queue<pair<int,int>> que;
	visited[0][0] = 1;
	result[0][0] = 1;
	que.push({0,0});
	
	while(!que.empty()){
		pair<int,int> cur = que.front(); que.pop();
//		if(cur.X == n-1 && cur.Y == m-1) break;
//		cout << '(' << cur.X << ", " << cur.Y << ") -> ";
		for(int i=0; i<4; i++){
			int x = cur.X + dx[i];
			int y = cur.Y + dy[i];	
			if(x < 0 || x >= n || y < 0 || y >= m) continue;
			if(visited[x][y] || map[x][y] != 1) continue;
			visited[x][y] = 1;
			que.push({x,y});
			result[x][y] = result[cur.X][cur.Y] + 1;
		}
	}

	printf("%d\n", result[n-1][m-1]);	
		
	return 0;
}
