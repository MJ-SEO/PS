#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair <int,int>> arr;
int dp[105];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n_line;
	cin >> n_line;

	for(int i=0; i<n_line; i++){
		int a_line, b_line;
		cin >> a_line >> b_line;
		arr.push_back({a_line, b_line});	
	}

	sort(arr.begin(), arr.end());
/*
	for(int i=0; i<n_line; i++){
		cout << "{" << arr[i].first << "," << arr[i].second << "}\n";
	}
*/	
	dp[0] = 1;

	for(int i=1; i<n_line; i++){
		dp[i] = 1;
		int mx = 0;
		for(int j=0; j<i; j++){
			if(dp[j] > mx && arr[j].second < arr[i].second){
				mx = dp[j];
				dp[i] = mx + 1;
			}
		}
	}
/*
	for(int i=0; i<n_line; i++){
		cout << "DP[" << i << "]: " << dp[i] << "\n";
	}
*/
	int LIS = 0;
	for(int i=0; i<n_line; i++){
		LIS = max(LIS, dp[i]);
	}

	cout << n_line - LIS << "\n";

	return 0;
}

