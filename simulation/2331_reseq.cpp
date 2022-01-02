#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

vector<int> arr; 
int flag;

int getnext(int n, int p){
	int nxt = 0;
	while(n > 0){
		nxt += pow(n%10, p);
		n = n/10;
	}
	return nxt;	
}

int checkin(int n){
	for(int i=0; i<arr.size(); i++){
		if(arr[i] == n) {
			flag = i;
			return 1;
		}
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A, P;
	int next;
	cin >> A >> P;
	arr.push_back(A);

	next = getnext(A, P);
	arr.push_back(next);
	

	while(1){
		next = getnext(next, P);
//		cout << "[DEBUG] " << next << "\n";
		if(checkin(next)) break;
		arr.push_back(next);
	}
	
	cout << flag << "\n";
	return 0;
}

