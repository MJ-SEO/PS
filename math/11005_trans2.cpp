#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

char itoa(int a){
	char temp;

	temp = a;

	return temp;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, b;
	cin >> n >> b;
	vector<int> arr;
	int count = 0;

	while(n > 0){	
		arr.push_back(n%b);
		n = n/b;
		count++;
	}
	
	for(int i=count-1; i>=0; i--){
		if(arr[i] < 10 && arr[i] >=0) cout << arr[i];
		else cout << itoa(arr[i] + 55);
	}


	return 0;
}

