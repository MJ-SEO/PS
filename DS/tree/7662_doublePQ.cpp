#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

multiset<int> pq;

int insert_queue(int n){
	pq.insert(n);
	return 0;
}

int delete_queue(int n){
	if(pq.size() == 0){
		return 1;
	}

	if(n == -1){
		pq.erase(pq.begin());
	}
	else if(n == 1){
		pq.erase(prev(pq.end()));
	}
	return 0;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for(int i=0; i<T; i++){
		int k;
		cin >> k;

		for(int j=0; j<k; j++){
			char op;
			int data;

			cin >> op >> data;

			if(op == 'I'){
				insert_queue(data);
			}
			else if(op == 'D'){
				delete_queue(data);
			}
			else{
				cout << "INPUT ERROR\n";
				return 0;
			}
		}

		if(pq.empty()){
			cout << "EMPTY\n";
		}
		else{
			cout << *prev(pq.end()) << " " << *pq.begin() << "\n";
		}
		pq.clear();
	}

	return 0;
}

