#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
	int n;
	cin >> n;
	
	priority_queue<int, vector<int>, greater<int> > que;

	for(int i=0; i<n; i++){
		int op;
		cin >> op;
		if(op==0){
			if(que.size() == 0){
				cout << "0\n";
			}
			else{
				cout << que.top() << "\n"; 
				que.pop();
			}
		}
		else{
			que.push(op);
		}
	}
        return 0;
}
