#include <iostream>
#include <algorithm>

using namespace std;

int glass[10010];
int dp[10010];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	int result = 0;
	cin >> n;

	for(int i=1; i<=n; i++){
		cin >> glass[i];	
	}

	if(n==1){
		cout << glass[1];
		return 0;
	}
	
	dp[1] = glass[1];
	dp[2] = glass[1] + glass[2];

	for(int i=3; i<=n; i++){
		dp[i] = max(dp[i-2] + glass[i], max(dp[i-3] + glass[i-1] + glass[i], dp[i-1]));
	}

	cout << dp[n];


	return 0;
}	
