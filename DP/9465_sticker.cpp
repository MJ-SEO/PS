#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[100005][5];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for(int i=0; i<n; i++){
		int num;
		int sum = 0;
		cin >> num;
		int table[2][num] = {0,};
		for(int j=0; j < num; j++){
			int temp;
			cin >> temp;
			table[0][j] = temp;
		}
		for(int j=0; j < num; j++){
			int temp;
			cin >> temp;
			table[1][j] = temp;
		}

		

	}


	return 0;
}

