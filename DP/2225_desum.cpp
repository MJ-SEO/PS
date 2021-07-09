#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int mod = 1000000000;
int dp[205][205];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for(int i=0; i<=n; i++){
		dp[0][i] = 0;
		dp[1][i] = 1;
	}

	for(int i=2; i<=k; i++){
		for(int j=0; j<=n; j++){
			for(int l=0; l<=j; l++){
				dp[i][j] = (dp[i][j] + dp[i-1][l]) % mod;
			}
		}
	}
	
	cout << dp[k][n] << "\n";

	return 0;
}

