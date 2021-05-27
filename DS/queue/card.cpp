#include <iostream>
#include <queue>

using namespace std;

int main(){
	int n;
	int result = 0;
	cin >> n;

	queue<int> que;
	for(int i=1; i<=n; i++){
		que.push(i);
	}

	while(que.size() != 1){
//		cout << "DEBUG size: " << que.size() << "\n";
		que.pop();
		int temp;
		temp = que.front(); que.pop();
		que.push(temp);
	}

	result = que.front();

	cout << result;
}
