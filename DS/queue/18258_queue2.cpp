#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

queue<int> que;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for(int i=0; i<N; i++){
		string op;
		cin >> op;

		if(op == "push"){
			int x;
			cin >> x;;
			que.push(x);
		}
		else if(op == "pop"){
			if(que.empty()) cout << "-1" << "\n";
			else{
				cout << que.front() << "\n";
				que.pop();
			}
		}
		else if(op == "size"){
			cout << que.size() << "\n";
		}
		else if(op == "empty"){
			if(que.empty()) cout << "1" << "\n";
			else cout << 0 << "\n";
		}
		else if(op == "front"){
			if(que.empty()) cout << "-1" << "\n";
			else{
				cout << que.front() << "\n";
			}
		}
		else if(op == "back"){
			if(que.empty()) cout << "-1" << "\n";
			else{
				cout << que.back() << "\n";
			}
		}
		else{
			cout << "INPUT ERROR\n" << "\n";
		}
	}

	return 0;
}

