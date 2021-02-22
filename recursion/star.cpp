#include <iostream>

using namespace std;

void func(int n, int zero){
	if(zero == n) return;
	
	zero++;
	func(n, zero);
}

int main(){
	int n;
	cin >> n;

	func(n, 0);

	return 0;
}
