#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

class cmp{
	public:
		bool operator() (int n1, int n2){
			if(abs(n1) != abs(n2)) return abs(n1) > abs(n2);
			return n1 > 0 && n2 < 0;
		}
};

priority_queue<int, vector<int>, cmp> que;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for(int i=0; i<N; i++){
		int x;
		cin >> x;
		if(x == 0){
			if(que.empty()) cout << 0 << "\n";
			else{
				cout << que.top() << "\n";
				que.pop();
			}
		}
		else{
			que.push(x);
		}
	}

	return 0;
}

