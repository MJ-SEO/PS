#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	queue<int> que;

	for (int i = 0; i < n; i++) {
		que.push(i+1);
	}  

	cout << "<";

	while(!que.empty()){
		int n = 0;
		for(int i=0; i<k-1; i++){
			n = que.front();
			que.pop();
			que.push(n);
		}

		n = que.front();
		que.pop();
		cout << n;
		if(que.size() > 0){
			cout << ", ";
		}
	}

	cout << ">";

	return 0;
}
