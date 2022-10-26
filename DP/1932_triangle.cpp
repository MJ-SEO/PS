#include <iostream>
#include <algorithm>

using namespace std;

int dp[505][505];
int arr[505][505];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int result = 0;
	cin >> n;

	for(int i=1; i<=n; i++){
		for(int j=1; j<=i ; j++){
			cin >> arr[i][j];
			arr[i][j] += max(arr[i-1][j-1], arr[i-1][j]);
			if(i==n) result = max(result, arr[i][j]);
		}
	}
/*
	for(int i=0; i<7; i++){
		for(int j=0; j<7; j++){
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
*/	
	cout << result << "\n";

	return 0;
}
