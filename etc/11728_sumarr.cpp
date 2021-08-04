#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr1;
vector<int> arr2;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for(int i=0; i<n+m; i++){
		int temp;
		cin >> temp;
		arr1.push_back(temp);
	}

	sort(arr1.begin(), arr1.end());

	for(int i=0; i<arr1.size(); i++){
		cout << arr1[i] << " ";
	}
	cout << "\n";

	return 0;
}

