#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}	
	sort(arr, arr+n);

	int m;
	cin >> m;
	int result[m];
	for(int i=0; i<m; i++){
		int temp;
		cin >> temp;
		cout << upper_bound(arr, arr+n, temp) - lower_bound(arr, arr+n, temp) << " ";
	}

	cout << "\n";


	return 0;
}

