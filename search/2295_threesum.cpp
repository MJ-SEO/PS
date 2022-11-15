#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int nset[1001];

vector<int> two;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int max_val = 0;

	for(int i=0; i<n; i++){
		cin >> nset[i];
	}
//	sort(nset, nset+n);

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			two.push_back(nset[i] + nset[j]);
		}
	}
	sort(two.begin(), two.end());

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(binary_search(two.begin(), two.end(), nset[i] - nset[j])){
				max_val = max(max_val, nset[i]);
			}
		}
	}

	cout << max_val << "\n";

	return 0;
}
