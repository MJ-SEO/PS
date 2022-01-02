#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int arr[510][2];
int DP[510][510];

int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0);
	
	int n; 
	cin >> n;
	int *p = (int*)malloc(sizeof(int) * n+1);

	for(int i=1; i<=n; i++){
		cin >> p[i] >> p[i+1];
	}

	for(int i=1; i<n; i++){
		DP[i][i+1] = p[i-1] * p[i] * p[i+1];
	}

	for(int m=2; m<=n; m++){
		for(int i=1; i<=n-m; i++){
			int j = i+m;
			for(int k=i; k<j; k++){
				int res = DP[i][k] + DP[k+1][j] + p[i] * p[k] * p[j+1];
				if(!DP[i][j] || DP[i][j] > res) DP[i][j] = res;
			}
		}
	}
	cout << DP[1][n];
}
