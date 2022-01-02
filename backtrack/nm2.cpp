#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[10];
bool isused[10];

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


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	func(1, 0);
/*
	for(int i=m; i<10; i++){
		arr[i] = 1;
	}

	do{
		for(int i=0; i<n; i++){
			if(arr[i] == 0)
				cout << i+1 << " ";
		}
		cout << "\n";
	}while(next_permutation(arr, arr+n));

*/
	return 0;
}
