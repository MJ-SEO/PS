#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string etob1[8] = {"0", "1", "10", "11", "100", "101", "110", "111"};
string etob[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;
	vector<string> arr;

	for(int i=str.size(); i>0; i--){
		if(i==1) arr.push_back(etob1[(str[i-1] - '0')]);
		arr.push_back(etob[(str[i-1] - '0')]);
	}
	
	for(int i=str.size()-1; i>=0; i--){
		cout << arr[i];
	}

	cout << "\n";

	return 0;
}

