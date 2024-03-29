#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int d[102][11];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	int sum = 0;
	cin >> n;

	for(int i=0; i<=9; i++){
		d[1][i] = 1;
	}
	
	for(int i=2; i<=n; i++){
		for(int j=0; j<=9; j++){
//			cout << "DEBUG " << d[i-1][j-1] << " " << d[i-1][j+1] << "       "<< j-1 << "\n";
			d[i][j] = (d[i-1][j-1] + d[i-1][j+1])%1000000000;
		}
	}

	for(int i=1; i<=9; i++){
		for(int j=0; j<=9; j++){
			cout << d[i][j] << " ";
		}
		cout << "\n";
	}

	for (int i = 1; i <= 9; i++){
	       	sum = (sum + d[n][i]) % 1000000000;
	}

	cout << sum << "\n";

	return 0;
}

