#include <iostream>
#include <algorithm>

using namespace std;

int dp[505][505];
int arr[505][505];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	for(int i=0; i<n; i++){
		for(int j=0; j<=i ; j++){
			cin >> arr[i][j];
		}
	}
	
	dp[1][0] = arr[0][0];
	for(int i=2; i<=n; i++){
		for(int j=0; j<i; j++){
			if(j==0){
				dp[i][j] = dp[i-1][j/2] + arr[i-1][j];
			}
			else if(j==i-1){
				dp[i][j] = dp[i-1][j/2] + arr[i-1][j];
			}
			else{
				dp[i][j] = max(dp[i-1][j-1] + arr[i-1][j], dp[i-1][j] + arr[i-1][j]);
			}
		}
	}

	int result = 0;
	for(int i=0; i<=n; i++){
		result = max(result, dp[n][i]);
	}

	cout << result << "\n";

	return 0;
}
