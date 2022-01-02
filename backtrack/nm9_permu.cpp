#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
bool isused[10];
/*
void func(int num, int k){
	if(k==m){
		for(int i=0; i<m; i++){
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for(int i=num; i<=n; i++){
		if(!isused[i]){
			arr[k] = i;
			isused[i] = 1;
			func(i+1, k+1);
			isused[i] = 0;
		}
	}
}

*/
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
//	func(1, 0);
	vector<int> arr(n);

	for(int i=0; i<n; i++){
		int t;
		cin >> t;
		arr[i] = t;
	}	
	
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(),arr.end()), arr.end());

	}

	do{
		for(int i=0; i<m; i++){
			cout << arr[i] << " ";
		}
		cout << "\n";
	}while(next_permutation(arr.begin(), arr.end()));

	return 0;
}
