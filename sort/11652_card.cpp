#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int count[100001];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<long long> arr;

	for(int i=0; i<n; i++){
		long long temp;
		cin >> temp;
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());

	long long result = arr[0];

	for(int i=0; i<n; i++){
		int count = 1;
		
	}

	cout << result << "\n";

	return 0;
}

