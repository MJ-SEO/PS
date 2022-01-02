#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[10];
int result[10];
bool isused[10];

void func(int k){
	if(k==m){
		for(int i=0; i<m; i++){
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}

	int dupl = 0; // Wht here?

	for(int i=0; i<n; i++){
		if(!isused[i] && arr[i]!=dupl){
			result[k] = arr[i];
			dupl = arr[i];
			isused[i] = 1;

			func(k+1);
			isused[i] = 0;
		}
	}
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	
	for(int i=0; i<n; i++){
		int t;
		cin >> t;
		arr[i] = t;
	}

	sort(arr, arr+n);

	func(0);
	return 0;
}
