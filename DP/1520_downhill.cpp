#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int map[501][501];
int dp[501][501];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};  

int n, m;

int
dfs(int x, int y){
	if((x == n) && (y == m)) return 1;
	if((x < 1 || x > n || y < 1 || y > m)) return 0;
	if(dp[x][y] != -1) return dp[x][y];

	dp[x][y] = 0;

	for(int i=0; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(map[nx][ny] < map[x][y]){
			dp[x][y] += dfs(nx, ny);
		}
	}

	return dp[x][y];

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
		        cin >> map[i][j];
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
		       	dp[i][j] = -1;
		}
	}

	dfs(1, 1);
	
	cout << dp[1][1] << "\n";

	return 0;
}

