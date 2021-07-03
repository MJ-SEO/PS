#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[100005];
int dp[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int mx = -10000;
	int n; 
	cin >> n;

	for(int i=1; i<=n; i++){
		cin >> arr[i];
	}
	
	dp[1] = arr[1];
	mx = max(mx, dp[1]);

	for(int i=2; i<=n; i++){
		if(dp[i-1] < 0){
			dp[i] = arr[i];
		}
		else{
			dp[i] = dp[i-1] + arr[i];
		}
		mx = max(mx, dp[i]);
	}
	for(int i=1; i<=n; i++){
		cout << dp[i] << " ";
	}
	cout << "\n";

	cout << mx << "\n";
	return 0;
}

