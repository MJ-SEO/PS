#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;


int DP[505][505];
void show(int n, int m){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout << DP[i][j] << " ";
		}
		cout << "\n";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int result = 0;
	cin >> n;
	int *p = (int*)malloc(sizeof(int)* n+1);

	for(int i=0; i<n; i++){
		int r, c;
		cin >> r >> c;
		p[i] = r;
		p[i+1] = c;
	}

	for(int i=0; i<n+1; i++){
		cout << p[i] << " ";
	}
	cout << "\n";

	show(n, n);
	cout << "\n";

	for(int r=1; r<=n; r++){
		for(int i=0; i<n-r+1; i++){
			int j = i+r-1;
			DP[i][j] = 2100000000;
			for(int k = i; k < j-1; k++){
				int t = DP[i][k] + DP[k+1][j] + p[i-1]*p[k]*p[j];
				if(DP[i][j] > t){
					DP[i][j] = t;
				}
			}
		}
	}
	show(n, n);

	cout << "re: " << result << "\n";
	return 0;

}
