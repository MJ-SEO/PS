#include <stdio.h>

int dp[42];
int dp2[42];

int main(){
	int n;
	scanf("%d", &n);
	
	dp[0] = 1;
	dp2[0] = 0;

	dp[1] = 0;
	dp2[1] = 1;

	for(int i=2; i<=40; i++){
		dp[i] = dp[i-1] + dp[i-2];
		dp2[i] = dp2[i-1] + dp2[i-2];
	}

	for(int i=0; i<n; i++){
		int temp;
		scanf("%d", &temp);

		printf("%d %d\n", dp[temp], dp2[temp]);		
	}
}
