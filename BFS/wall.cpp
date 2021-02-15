#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <tuple>

using namespace std;
#define X first
#define Y second


int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dz[6] = {};
int map[1000][1000][2];
bool visited[1000][1000];
int result[1000][1000];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);


	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%1d", &map[i][j]);
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			printf("%d", map[i][j]);
		}
		printf("\n");
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			result[i][j] = -1;
		}
	}

	queue<tuple<int,int,int> que;
//	queue<pair<int,int>> que;
	visited[0][0] = 1;
	result[0][0] = 1;
	que.push({0,0,0});
	int flag = 0;

	while(!que.empty()){
//		pair<int,int> cur = que.front(); que.pop();
		tuple<int,int,int> cur = que.front(); que.pop();
//		if(cur.X == n-1 && cur.Y == m-1) break;
//		cout << '(' << cur.X << ", " << cur.Y << ") -> ";

		for(int i=0; i<4; i++){
			int x = get<0>(cur) + dx[i];
			int y = get<1>(cur) + dy[i];	
			int z = 0;
			if(x < 0 || x >= n || y < 0 || y >= m) continue;
			if(visited[x][y] == 1) continue;
			if() continue;
			
			visited[x][y] = 1;
			que.push({x,y,z});
			result[x][y] = result[cur.X][cur.Y] + 1;
		}
	}

	printf("%d\n", result[n-1][m-1]);	
		
	return 0;
}
