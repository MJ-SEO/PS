#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long dp[31][31];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for(int i=0; i<=30; i++){
		for(int j=0; j<= 30; j++){
			if(i > j) continue;
			if(i==0) dp[j][i] = 1;
			else dp[j][i] = dp[j-1][i] + dp[j][i-1];
		}
	}

	int n_pill;
	while(1){
		cin >> n_pill;
		if(n_pill == 0) break;
		cout << dp[n_pill][n_pill] << "\n";	
	}
	return 0;
}

