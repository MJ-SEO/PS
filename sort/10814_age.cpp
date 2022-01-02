#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <tuple>

using namespace std;

bool cmp(tuple<int, string, int>& a, tuple<int, string, int>& b){
	if(get<0>(a) < get<0>(b)){
		return true;
	}
	else if(get<0>(a) == get<0>(b)){
		return get<2>(a) < get<2>(b);
	}
	else{
		return false;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	vector<tuple<int, string, int>> lis(n);

	for(int i=0; i<n; i++){
		cin >> get<0>(lis[i]) >> get<1>(lis[i]);
		get<2>(lis[i]) = i;
	}
	
	sort(lis.begin(), lis.end(), cmp);
	
	for(int i=0; i<n; i++){
		cout << get<0>(lis[i]) << " " <<  get<1>(lis[i]) << "\n";
	}
	return 0;
}

