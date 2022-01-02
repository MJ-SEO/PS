#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[10001];
int coins[101];

int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);

        int n, k;
        int result = 0;
        cin >> n >> k;

        for(int i=0; i<n; i++){
                cin >> coins[i];
        }

        dp[0] = 1;

        for (int i = 0; i < n; i++){
                for (int j = coins[i]; j <= k; j++)
                        dp[j] += dp[j - coins[i]];
        }
        cout << dp[k] << "\n";

        return 0;
}
