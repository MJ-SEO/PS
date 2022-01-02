#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[22][22][22];

int 
rew (int a, int b, int c){
	printf("DEBUG %d %d %d\n", a, b, c);
	if(a<=0 || b<=0 || c<=0) return 1;
	else if (a>20 || b>20 || c>20) return rew(20, 20, 20);
	else if (a < b && b <c) return rew(a, b, c-1) + rew(a, b-1, c-1) - rew(a, b-1, c);
	else return rew(a-1, b, c) + rew(a-1, b-1, c) + rew(a-1, b, c-1) - rew(a-1, b-1, c-1);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for(int i=0; i<=21; i++){
		for(int j=0; j<=21; j++){
			for(int k=0; k<=21; k++){
				if(i<=0 || j<=0 || k<=0) dp[i][j][k] = 1;
				else if (i>20 || j>20 || k>20) dp[i][j][k] = 1048576;
				else if (i < j && j <k) dp[i][j][k] = dp[i][j][k-1] + dp[i][j-1][k-1] - dp[i][j-1][k];
				else dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k] + dp[i-1][j][k-1] - dp[i-1][j-1][k-1];
			}
		}
	}

	while(1){
		int a, b, c;
		cin >> a >> b >> c;
		if(a == -1 && b == -1 && c == -1) break;
		if(a <= 0 || b <= 0 || c <=0){
			cout << "w(" << a << ", " << b << ", " << c << ") = " << dp[0][0][0] << "\n";
		}
		else if(a > 20 || b >20 || c > 20){
			cout << "w(" << a << ", " << b << ", " << c << ") = " << dp[20][20][20] << "\n";
		}
		else{
			cout << "w(" << a << ", " << b << ", " << c << ") = " << dp[a][b][c] << "\n";
		}
	}	

	return 0;
}

