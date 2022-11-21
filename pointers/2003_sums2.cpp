#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
long long arr[10005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	int cnt = 0;

	for(int i=0; i<N; i++){
		cin >> arr[i];
	}

	int en = 0;
	int tot = arr[0];

	for(int st=0; st<N; st++){
		if(tot == M) {
			cnt++;
		}		
		while(tot < M && en < N){
			en += 1;
			if(en != N) {
				tot += arr[en];
				if(tot == M) {
					cnt++;
				}
			}
		}
		if(en == N) break;
		
		tot -= arr[st];
	}

	cout << cnt << "\n";

	return 0;
}

