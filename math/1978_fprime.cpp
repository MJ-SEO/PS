#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


bool isprime(int n){
	if(n==1) return false;
	for(int i=2; i * i <= n; i++){
		if(n%i == 0) return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	int n_prime = 0;

	for(int i=0; i<n; i++){
		int temp;
		cin >> temp;

		if(isprime(temp)){
			n_prime++;
		}
	}

	cout << n_prime << "\n";

	return 0;
}

