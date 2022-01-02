#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[1001][1001];
int route[1001][1001];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int result = 0;
	string a, b;

	cin >> a >> b;
	cout << "DEBUG: " << a.size() << " " << b.size() << "\n";
	
	for(int i=1; i<a.size()+1; i++){
		for(int j=1; j < b.size()+1; j++){
			if(a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1]+1;
			}
			else{
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
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
	
	cout << "re: " << result << "\n";
	return 0;
}
