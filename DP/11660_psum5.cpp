#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int map[1030][1030];
int dp[1030][1030];

int
get_psum(int x1, int y1, int x2, int y2){

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;

	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >> map[i][j];	
			dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + map[i][j];
		}
	}

	for(int i=0; i<m; i++){
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int result = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1];
		cout << result << "\n";	
	}

	return 0;
}

