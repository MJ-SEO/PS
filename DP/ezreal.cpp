#include <iostream>
#include <algorithm>

using namespace std;

int dp[1520];

int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
	int n;
	cin >> n;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 3;

	while(){
		long long temp = 0;
		for(int j=2; j<=n-2; j++){
			temp += 2*dp[j];
			temp = temp % 1000000007;
		}
		dp[i] = temp+1;
	}

	cout << dp[n] << "\n";

        return 0;
}

