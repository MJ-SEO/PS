#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long dp[1000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for(int i=4; i<1000005; i++){
		dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % 1000000009;
	}


	for(int i=0; i<N; i++){
		int x;
		cin >> x;

		cout << dp[x] << "\n";
	}

	return 0;
}

