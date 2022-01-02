#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[100005][2];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for(int i=0; i<n; i++){
		int num;
		int sum = 0;
		cin >> num;
		int table[num][2] = {0,};
		for(int j=0; j < num; j++){
			int temp;
			cin >> temp;
			table[j][0] = temp;
		}
		for(int j=0; j < num; j++){
			int temp;
			cin >> temp;
			table[j][1] = temp;
		}

		dp[i][0] = max(dp[i-1][0], dp[i-2][0]) + table[i][0];
		dp[i][1] = max(dp[i-1][1], dp[i-2][1]) + table[i][1];
	}

	cout << max(dp[n][0], dp[n][1]) << "\n";

	return 0;
}

