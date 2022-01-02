#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int d[12];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	d[1] = 1;
	d[2] = 2;
	d[3] = 4;
	
	for(int i=4; i<12; i++){
		d[i] = d[i-1] + d[i-2] + d[i-3];
	}

	int n;
	cin >> n;

	for(int i=0; i<n; i++){
		int temp;
		cin >> temp;
	 	cout << d[temp] << "\n";	
	}
	return 0;
}

