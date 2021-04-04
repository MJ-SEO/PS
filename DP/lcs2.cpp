#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int dp[1001][1001];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int result = 0;
	string a, b;

	cin >> a >> b;
	int l1 = a.size();
	int l2 = b.size();
	cout << "DEBUG: " << l1 << " " << l2 << "\n";

	for(int i=1; i<a.size()+1; i++){
		for(int j=1; j < b.size()+1; j++){
			if(a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1]+1;
			}
			else{
				if(dp[i][j-1] >= dp[i-1][j]){
					dp[i][j] = dp[i][j-1];
				}
				else{
					dp[i][j] = dp[i-1][j];
				}
			}
		}
	}

	for(int i=0; i<a.size()+1; i++){
		for(int j=0; j<b.size()+1; j++){
			cout << dp[i][j] << " ";
			result = max(result, dp[i][j]);
		}
		cout << "\n";
	}
	
	int i = l1;
	int j = l2;
	vector<char> ans;

	while(i!=0 && j!=0){
		if(dp[i][j] == dp[i-1][j]){
			i--;	
		}
		else if(dp[i][j] == dp[i][j-1]){
			j--;
		}
		else{
			ans.push_back(a[i-1]);
			i--;
			j--;		
		}
	}
	

	cout << result << "\n";

	for(int i=ans.size()-1; i>=0 ; i--){
		cout << ans[i];
	}
	cout << "\n";
	return 0;
}
