#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

int arr[100005];

int bs(int target, int start, int end){
	if(start > end){
		return 0;
	}
	else if(start == end){
		if(arr[start] == target) return 1;
		else return 0;
	}
	else{
		int middle = (start+end)/2;
		if(arr[middle] == target) return 1;
		else if(arr[middle] > target) return bs(target, start, middle-1);
		else return bs(target, middle+1, end);
	}

	return 0;
}

int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
	
	int n, m;
	cin >> n;

	vector<int> result;

	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	sort(arr, arr+n);

	cin >> m;
	for(int i=0; i<m; i++){
		int temp;
		cin >> temp;
		result.push_back(bs(temp, 0, n-1));
	}
	
	for(int i=0; i<m; i++){
		cout << result[i] << "\n";
	}

	
        return 0;
}

