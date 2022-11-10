#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
	return a.second < b.second;
}

pair<int,int> arr[100005];

int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
	
	int n;
	cin >> n;
	int result = 0;


	for(int i=0; i<n; i++){
		cin >> arr[i].second >> arr[i].first;
	}

	sort(arr, arr+n);
	
	int t = 0;
	for(int i=0; i<n; i++){
		if(t > arr[i].second) continue;
		result++;
		t = arr[i].first;
	}

	cout << result;
     	return 0;
}

