#include <bits/stdc++.h>
using namespace std;


int arr[100006];

int main(void) {
  	ios::sync_with_stdio(0);
  	cin.tie(0);
  	int result = 0;
  	int n;
	int x;
  	cin >> n;

	int* list = (int*)malloc(sizeof(int)*n);

	for(int i=0; i<n; i++){
		int t;
		cin >> t;
		arr[t] = 1;
		list[i] = t;
	}

	cin >> x;

	for(int i=0; i<n; i++){
		if(list[i] <= x && arr[x - list[i]] == 1){
			result++;
		}
	}


  	cout << result/2 << "\n";
}
