#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int Minute;

long long dp[100001][8];

#define div 1000000007

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> Minute;

	dp[1][1] = 1;
	dp[1][2] = 1;

	for(int i=2; i<=Minute; i++){
		dp[i][0] = (dp[i-1][1] + dp[i-1][2])%div; 
		dp[i][1] = (dp[i-1][0] + dp[i-1][2] + dp[i-1][3])%div; 
		dp[i][2] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][3] + dp[i-1][4])%div;  
		dp[i][3] = (dp[i-1][1] + dp[i-1][2] + dp[i-1][4] + dp[i-1][5])%div;  
		dp[i][4] = (dp[i-1][2] + dp[i-1][3] + dp[i-1][5] + dp[i-1][7])%div;  
		dp[i][5] = (dp[i-1][3] + dp[i-1][4] + dp[i-1][6])%div; 
		dp[i][6] = (dp[i-1][5] + dp[i-1][7])%div; 
		dp[i][7] = (dp[i-1][4] + dp[i-1][6])%div; 
	}

	cout << dp[Minute][0] << "\n";

	return 0;
}

