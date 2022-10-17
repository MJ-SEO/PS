#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(const string& a, const string& b){
	if(a.length() != b.length()){
		return a.length() < b.length();
	}
	else{
		int n = 0, m = 0;
		for(int i=0; i<a.length(); i++){
			if(a[i] >= 48 && a[i] <= 57){
				n+=a[i]-48;
			}
			if(b[i] >= 48 && b[i] <= 57){
				m+=b[i]-48;
			}
		}
		if(n != m)
			return n<m;
		else
			return a<b;
	}
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
		arr.push_back(word);
	}
	
	sort(arr.begin(), arr.end(), cmp);

	for(int i=0; i<arr.size(); i++){
		cout << arr[i] << "\n"; 
	}

	return 0;
}	
