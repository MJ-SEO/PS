#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[1000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 2;

	for(int i=3; i<=n; i++){
		dp[i] = (dp[i-1] + dp[i-2]) % 15746;
	}

	cout << dp[n] << "\n";

	return 0;
}

