#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> primes;

bool isprime(int n){
	if(n == 1) return false;
	for(int i=2; i * i <= n; i++){
		if(n % i == 0) return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	if(N == 1){
		cout << 0 << "\n";
		return 0;
	}

	int cnt = 0;

	for(int i=2; i<=N; i++){
		if(isprime(i)) primes.push_back(i);
	}

	int en = 0;
	int tot = primes[0];

	int size = primes.size();

	for(int st=0; st<size; st++){
		if(tot == N){
			cnt++;
		}

		while(en < size && tot < N){
			en += 1;
			if(en != size){
				tot += primes[en];
				if(tot == N) {
					cnt++;
				}
			}
		}
		if(en == size) break;

		tot -= primes[st];
	}

	cout << cnt << "\n";

	return 0;
}

