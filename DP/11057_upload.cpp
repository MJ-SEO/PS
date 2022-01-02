#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long int dp[1002][11];

int summ(int n, int k){
	int sum = 0;
	for(int i=0+k; i<=9; i++){
		sum = (sum + dp[n][i]) % 10007;
	}
	return sum;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	int sum = 0;
	cin >> n;

	for(int i=0; i<=9; i++){
		dp[1][i] = 1;
	}

	for(int i=2; i<=n; i++){
		for(int j=0; j<=9; j++){
			dp[i][j] = summ(i-1, j); 
		}
	}

	cout << summ(n, 0) << "\n";

	return 0;
}

