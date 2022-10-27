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
	
	int result = 0;

	for(int i=1; i<=n; i++){
		int sum = 0;
		for(int j=1; j<i; j++){
			if(arr[j] < arr[i]){
				sum = max(sum, dp[j]);
			}
		}
		cout << sum << " ";
		dp[i] = sum + arr[i];
		result = max(result, dp[i]);
	}
	
	cout << "\n";
	for(int i=1; i<=n; i++){
		cout << dp[i] << " ";
	}
	cout << "\n";

	cout << result;
	return 0;
}

