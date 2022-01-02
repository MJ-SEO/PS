#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int p[10005];
int dp[1005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for(int i=1; i<=n; i++){
		int temp;
		cin >> temp;
		p[i] = temp;
	}

	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			dp[i] = max(dp[i], dp[i-j] + p[j]);
		}
	}
/*
	for(int i=1; i<=n; i++){
		cout << dp[i] << " ";
	}
	cout << "\n";
*/	
	cout << dp[n] << "\n";

	return 0;
}

