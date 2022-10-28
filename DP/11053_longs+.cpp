#include <iostream>
#include <algorithm>

using namespace std;

int arr[1050];
int d[1050];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int result = 0;

	for(int i=0; i<n; i++){
		cin >> arr[i];
		d[i] = 1;
	}

	
	for(int i=0; i<n; i++){
		for(int j=0; j<i; j++){
			if(arr[j] < arr[i]){
				d[i] = max(d[i], d[j] + 1);
			}
		}
	}

	for(int i=0; i<n; i++){
		cout << d[i] << " ";
		result = max(result, d[i]);
	}
	cout << "\n";

	cout << result << "\n";

}
