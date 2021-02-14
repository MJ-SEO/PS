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
int map[500][500];
bool visited[500][500];
int result[500][500];

int main(){
	int n, m;
	int mx = 0;
	int num = 0;

	scanf("%d %d", &n, &m);

//	cout << "DEBUG N, M: " << n <<" "<< m << endl;

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d", &map[i][j]);
		}
	}
/*
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			printf("%d", map[i][j]);
		}
		printf("\n");
	}
*/
	queue<pair<int,int>> que;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(map[i][j] == 0 || visited[i][j]) continue;
			num++;
			visited[i][j] = 1;
			que.push({i,j});
			int area = 0;

			while(!que.empty()){
				area++;
				pair<int,int> cur = que.front(); que.pop();
				for(int i=0; i<4; i++){
					int x = cur.X + dx[i];
					int y = cur.Y + dy[i];	
					if(x < 0 || x >= n || y < 0 || y >= m) continue;
					if(visited[x][y] || map[x][y] != 1) continue;
					visited[x][y] = 1;
					que.push({x,y});
				}
			}
			mx = max(mx, area);
		}
	}

	printf("%d\n", num);	
	printf("%d\n", mx);	
		
	return 0;
}
