#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int map[105][105];
long dp[105][105];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;

	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cin >> map[i][j];
		}
	}

	dp[N][N] = 1;

	for(int i=N; i>=1; i--){
		for(int j=N; j>=1; j--){
			if(i==N && j==N) continue;
			dp[i][j] =	dp[i][j + map[i][j]] + dp[i + map[i][j]][j];
		}
	}

	cout << dp[1][1] << "\n";

	return 0;
}

