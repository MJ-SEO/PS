#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;

	cin >> n >> m >> k;

	int result = min(min(n/2, m), (n+m-k)/3);

	cout << result << "\n";
	

	return 0;
}

