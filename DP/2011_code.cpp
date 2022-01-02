#include <iostream>
#include <string>
using namespace std;
long long dp[5001];
long long code[5001];
int main()
{
	string s;
	getline(cin, s);
	int len = s.length();
	if (len > 5000) exit(-1);

	for (int i = 0; i < len; i++) code[i + 1] = s[i] - '0';
	if (s[0] - '0' == 0) cout << 0 << endl;
	else
	{
		dp[0] = 1;
		for (int i = 1; i <= len; i++){
			if (code[i] >= 1 && code[i] <= 9)
				dp[i] = dp[i] + dp[i - 1];

			int t = code[i - 1] * 10 + code[i];
			if (t >= 10 && t <= 26)
				dp[i] = (dp[i] + dp[i - 2])%1000000;
		}
		cout << dp[len] << endl;
	}
	return 0;
}
