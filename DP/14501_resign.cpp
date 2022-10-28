#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int duration[1500001];
int price[1500001];
int dp[1500001];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for(int i=1; i<=N; i++){
		cin >> duration[i] >> price[i];
	}

	for(int i=1; i<=N; i++){
		dp[i] = max(dp[i], dp[i-1]);

		if(i + duration[i]-1 <= N){
			dp[i + duration[i]] = max(dp[i + duration[i]], dp[i] + price[i]);
		}
	}

	cout << max(dp[N], dp[N+1]) << "\n";

	return 0;
}

