#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(const string& a, const string& b){
	if(a.length() == b.length()){
		return a<b;
	}
	return a.length() < b.length();
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	cin.clear();
	
	vector<string> arr;

	for(int i=0; i<n; i++){
		string word;
		cin >> word;
		if(find(arr.begin(), arr.end(), word) == arr.end())
			arr.push_back(word);
	}
	
	sort(arr.begin(), arr.end(), cmp);

	for(int i=0; i<n; i++){
		cout << arr[i] << "\n"; 
	}

	return 0;
}	
