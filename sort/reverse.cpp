#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>

using namespace std;


int main(){
	int n;
	cin >> n; 

	vector<string> arr(n);
	vector<long long> result;

	for(int i=0; i< n; i++){
		cin >> arr[i];
		reverse(arr[i].begin(), arr[i].end());
		result.push_back(stoll(arr[i]));	
	}

	sort(result.begin(), result.end());

	for(int i=0; i< n; i++){
		cout << result[i] << "\n";
	}
	return 0;
}
/*
bool cmp(int a, int b){
	return 	a<b;
}

int sti(string str){
	int result = 0;
	
	queue<char> st;

	for(int i=str.length()-1; i>=0; i--){
		st.push(str[i]);
	}


	int size = st.size();
	string temp;
	
	for(int i=0; i<size; i++){
		result += (st.front() - 48) * pow(10, st.size()-1);
		st.pop();
	}

	return result;
}
*/
