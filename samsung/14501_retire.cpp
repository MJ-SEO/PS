#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int dp[16];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for(int i=0; i<N; i++){
		cin >> date >> pay;
		if(i == 0){
			dp[i] = pay;
		}
		else{
			
			dp[i] = max();
		}
	}

	cout << dp[N];

	return 0;
}

