#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int map[105][105];
int dp[105][105];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> map[i][j];
		}
	}

	


	return 0;
}

