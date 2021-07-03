#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[100005];
int dp[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n; 
	cin >> n;
	
	for(int i=1; i<=n; i++){
		cin >> arr[i];
	}

	dp[1] = arr[1];

	for(int i=2; i<=n; i++){
		if(arr[i] >= 0){
			dp[i][0] = dp[i-1][0] + arr[i];
			dp[i][1] = dp[i-1][1] + arr[i];
		}
		else{
			dp[i][0] = 0;
			dp[i][1] = dp[i-1][1] + arr[i];
		}
		mx1 = max(mx1, dp[i][0]);
		mx2 = max(mx2, dp[i][1]);
	}

	for(int i=0; i<=n; i++){
		cout << dp[i][0] << " ";
	}
	cout << "\n";
	for(int i=0; i<=n; i++){
		cout << dp[i][1] << " ";
	}
	cout << "\n";

	cout << max(mx1, mx2) << "\n";

	
	return 0;
}

