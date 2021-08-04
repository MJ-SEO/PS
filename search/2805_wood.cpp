#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[1000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n, m;
	cin >> n >> m;

	long long maxlen = 0;

	for(int i=0; i<n; i++){
		cin >> arr[i];
		maxlen = max(maxlen, arr[i]);
	}

	long long result = 0, st = 1, en = maxlen, mid;

	while(st <= en){
		mid = (st+en)/2;
		cout << "[DEBUG] " << mid << " ";

		long long temp = 0;
		for(long long i=0; i<n; i++){
			if(arr[i] > mid){
				temp += arr[i] - mid;
			}
		}
		cout << temp << "\n";

		if(temp >= m){
			st = mid+1;
			result = max(result, mid);
		}
		else{
			en = mid -1;
		}
	}
	cout << result << "\n";
	return 0;
}

