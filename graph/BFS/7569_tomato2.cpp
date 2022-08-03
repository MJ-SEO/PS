#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>
#include <tuple>

using namespace std;
#define X first
#define Y second


int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};
int map[100][100][100];
int result[100][100][100];

int main(){
	int n, m, h;
	scanf("%d %d %d", &n, &m, &h);
	
	queue<tuple<int,int,int>> que;
	for(int k=0; k<h; k++){
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &map[i][j][k]);
			if(map[i][j][k] == 1){
//				visited[i][j] = 1;
//				result[i][j] = 1;
				que.push({i,j,k});			
			}
			if(map[i][j][k] == 0){
				result[i][j][k] = -1;
			}
		}
	}
	}

	while(!que.empty()){
		tuple<int,int,int> cur = que.front(); que.pop();
//		if(cur.X == n-1 && cur.Y == m-1) break;
//		cout << '(' << cur.X << ", " << cur.Y << ") -> ";
		for(int i=0; i<6; i++){
			int x = get<0>(cur) + dx[i];
			int y = get<1>(cur) + dy[i];	
			int z = get<2>(cur) + dz[i];
			if(x < 0 || x >= m || y < 0 || y >= n || z < 0 || z>=h) continue;
			if(result[x][y][z] >= 0) continue;
			que.push({x,y,z});
			result[x][y][z] = result[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
		}

/*
		for(int k=0; k<h; k++){
			printf("[DEBUG] %d층\n", k+1);
				for(int i=0; i<m; i++){
					for(int j=0; j<n; j++){
					printf("%d ", result[i][j][k]);
				}
				printf("\n");
			}
		} */
	}
	int nn = 0;

	for(int k=0; k<h; k++){
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(result[i][j][k] == -1){
				printf("-1\n");
				return 0;
			}
			nn = max(nn, result[i][j][k]);
		}
	}     
	}

	printf("%d\n", nn);
		
	return 0;
}
