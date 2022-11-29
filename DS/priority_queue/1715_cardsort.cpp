#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, cnt;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for(int i=0; i<N; i++){
		int size;
		cin >> size;
		pq.push(size);
	}

	while(pq.size() > 1){
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		cnt += a + b;
		pq.push(a+b);
	}

	cout << cnt << "\n";
	return 0;
}

