#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long int dp[102];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	dp[1] = dp[2] = dp[3] = 1;
	dp[4] = dp[5] = 2;

	for(int i=0; i<n; i++){
		int temp;
		cin >> temp;
			
		for(int i=6; i<=temp; i++){
			dp[i] = dp[i-1] + dp[i-5];
		}

		cout << dp[temp] << "\n";
	}

	return 0;
}

