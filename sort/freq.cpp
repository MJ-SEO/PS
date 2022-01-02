#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(int a, int b){
	return 	b<a;
}

int main(){
	int n, c;
	cin >> n >> c; // n은 반복횟수, c는 max값

	cout << n << " " << c << "\n";

	vector<int> arr;

	for(int i=0; i< n; i++){
		int temp;
		cin >> temp;
		arr.push_back(temp);	

	}

	sort(arr.begin(), arr.end(), cmp);

	for(int i=0; i< n; i++){
		cout << arr[i] << " ";
	}
	return 0;
}
