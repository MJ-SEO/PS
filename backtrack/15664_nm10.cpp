#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int store[10];
int result[10];
bool isused[10];

void func(int k, int t){
	if(k==m){
		for(int i=0; i<m; i++){
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}

	int dupl = 0; // Why here?

	for(int i=t; i<n; i++){
		if(store[i] != dupl){
			dupl = store[i];

			isused[i] = true;
			result[k] = store[i];
			func(k+1, i);
			isused[i] = false;
		}
	}
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	
	for(int i=0; i<n; i++){
		cin >> store[i];
	}

	sort(store, store+n);

	func(0, 0);
	return 0;
}
