#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long arr[10005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int k, n;
	cin >> k >> n;
 
	long long maxlen = 0;

	for(int i=0; i<k; i++){
	       	cin >> arr[i];
		maxlen = max(maxlen, arr[i]);
	}

	long long result = 0, st = 1, en = maxlen, mid;

	while(st <= en){
		mid = (st+en)/2;
		cout << "[DEBUG] " << mid << " ";

		long long temp = 0;

		for(int i=0; i<k; i++){
			temp += arr[i] / mid;
		}
		cout << temp << "\n";

		if(temp >= n){
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

