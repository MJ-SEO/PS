#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	vector<pair<int, int>> arr;

	for(int i=0; i<n; i++){
		int x, y;
		cin >> x >> y;
		arr.push_back({y,x});
	}

	sort(arr.begin(), arr.end());

	for(int i=0; i<n; i++){
		cout << arr[i].second << " " << arr[i].first << "\n";
	}

	return 0;
}

