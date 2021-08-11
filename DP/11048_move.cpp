#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int map[1001][1001];
int dp[1001][1001];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> map[i][j];
		}
	}

	dp[1][1] = map[0][0];

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			dp[i][j] =  max(dp[i][j-1] + map[i-1][j-1], dp[i-1][j] + map[i-1][j-1]);
		}
	}
	
	cout << dp[n][m] << "\n";

	return 0;
}

