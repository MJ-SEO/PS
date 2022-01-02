#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;
	vector<string> arr;
	
	int n = str.size();

	for(int i=0; i<n; i++){
		arr.push_back(str);
		str.replace(0,1,"");
	}

	sort(arr.begin(), arr.end());

	for(int i=0; i < arr.size(); i++){
		cout << arr[i] << "\n";
	}

	return 0;
}

