#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T, N, M;
int coins[25];
int dp[10005];

void solve(){
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> coins[i];
	}
	cin >> M;

	dp[0] = 1;

	for(int i=0; i<N; i++){
		for(int j=coins[i]; j<=M; j++){
			dp[j] = dp[j] + dp[j-coins[i]];
		}
	}

	cout << dp[M] << "\n";

	for(int i=0; i<=N; i++) coins[i] = 0;
	for(int i=0; i<=M; i++) dp[i] = 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;

	for(int i=0; i<T; i++){
		solve();		
	}

	return 0;
}

