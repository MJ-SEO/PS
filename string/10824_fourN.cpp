#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string one, two, three, four;
	cin >> one >> two >> three >> four;
	
	one += two;
	three += four;

	long long result = stoll(one) + stoll(three);

	cout << result << "\n";

	return 0;
}

