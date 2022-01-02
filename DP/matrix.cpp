#include <iostream>
#include <algorithm>

using namespace std;

int A[101][101];
int B[101][101];
int R[101][101];

int main(){	
	cin.tie(0);
	int n, m;
	cin >> n >> m;

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			int t;
			cin >> t;
			A[i][j] = t;
		}
	}
	
	int n2, m2;
	cin >> n2 >> m2;
	for(int i=0; i<n2; i++){
		for(int j=0; j<m2; j++){
			int t;
			cin >> t;
			B[i][j] = t;
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m2; j++){
			for(int k=0; k<m; k++){
				R[i][j] += (A[i][k] * B[k][j]);
			}
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m2; j++){
			cout << R[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
