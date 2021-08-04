#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int arr[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, c;
	cin >> n >> c;

	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	
	sort(arr, arr+n);

	int st = 1, en = arr[n-1] - arr[0], mid, result;

	while(st <= en){
		mid = (st+en)/2;
		cout << "[DEBUG] mid: " << mid << "\n";
		int count = 1;
		int start = arr[0];

		for(int i=1; i<n; i++){
			if(arr[i] - start >= mid){
				count++;
				start = arr[i];		
		//		cout << "[DEBUG] start: " << start << " " << i << " " << count<<  "\n";
			}	
		}

		if(count >= c){
			result = mid;
			st = mid + 1;
		}
		else{
			en = mid - 1;
		}
	}
	cout << result << "\n";
	return 0;
}
