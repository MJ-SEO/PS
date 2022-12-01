#include <bits/stdc++.h>
using namespace std;


int arr[1000005];
bool arr2[1000005];
int N, X;

int main(void) {
  	ios::sync_with_stdio(0);
  	cin.tie(0);
  	int result = 0;

  	cin >> N;

	for(int i=0; i<N; i++){
		int temp;
		cin >> temp;
		arr[i] = temp;
		arr2[arr[i]] = 1;
	}

	cin >> X;

	for(int i=0; i<N; i++){
		if(X - arr[i] > 0 && arr2[X - arr[i]]) result++;
	}

  	cout << result/2 << "\n";
}
