#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int N, K;
int M, V;

multiset<int> knap;
pair<int, int> jewel[300005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	for(int i=0; i<N; i++){
		cin >> jewel[i].second >> jewel[i].first;
	}
	sort(jewel, jewel+N);

	for(int i=0; i<K; i++){
		int c;
		cin >> c;
		knap.insert(c);
	}

	long long max_val = 0;

	for(int i=N-1; i>=0; i--){
		int m, v;
		m = jewel[i].second;
		v = jewel[i].first;
		auto iter = knap.lower_bound(m);
		if(iter == knap.end()) continue;

		max_val += v;
		knap.erase(iter);
	}

	cout << max_val << "\n";
	return 0;
}

