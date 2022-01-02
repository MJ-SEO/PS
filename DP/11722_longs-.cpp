#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[1005];
int dp[1005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for(int i=1; i<=n; i++){
		cin >> arr[i];
	}

	for(int i=1; i<=n; i++){
		int mx = 0;
		for(int j=1; j<i; j++){
			if(arr[j] > arr[i]){
				mx = max(mx, dp[j]);
			}
		}
		dp[i] = mx + 1;
	}
/*
	for(int i=0; i<=n; i++){
		cout << dp[i] << " ";
	}
	cout << "\n";
*/
	sort(dp, dp+n+1);
	cout << dp[n];
	return 0;
}

