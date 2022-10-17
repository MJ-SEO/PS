#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

pair<int, int> freq[1001];
int idx = 0;
int re;

bool cmp(pair<int, int> a, pair<int, int> b){
	return a.second > b.second;
}

bool contain(int t){
	for(int i=0; i<idx+1; i++){
		if(freq[i].first == t){
			re = i;
			return true;
		} 
	}
	return false;
}

int main(){
	int n, c;
	cin >> n >> c; // n은 반복횟수, c는 max값

	vector<int> arr;

	for(int i=0; i< n; i++){
		int temp;
		cin >> temp;
		arr.push_back(temp);	

	}

//	sort(arr.begin(), arr.end());

	freq[idx].first = arr[0];
	freq[idx].second = 1;

	for(int i=1; i < n; i++){
		if(contain(arr[i])){
			freq[re].second++;
		}
		else{
			idx++;
			freq[idx].first = arr[i];
			freq[idx].second = 1;
		}
	}

	stable_sort(freq, freq+idx+1, cmp);

	for(int i=0; i < idx+1 ; i++){
		for(int j=0; j < freq[i].second; j++){
			cout << freq[i].first << " ";
		}
	}

	return 0;
}
