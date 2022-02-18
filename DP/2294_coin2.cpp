#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;

int dp[10001];
int coins[101];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	for(int i=1; i<=N; i++){
		cin >> coins[i];
	}
	
	for(int i=1; i<=K; i++){
		dp[i] = 1000000000;
	}
	
	for(int i=1; i<=N; i++){
		dp[coins[i]] = 1;
	}

	dp[0] = 0;

	for(int i=1; i<=N; i++){
		for(int j=coins[i]; j<=K; j++){
			dp[j] = min(dp[j], dp[j-coins[i]] + 1);
		}
	}

	if(dp[K] == 1000000000) cout << -1 << "\n";
	else cout << dp[K] << "\n";

	return 0;
}

