#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int hp[10];
int weight[10];
int result;
int broken;


void func(int k){
	if(k==N){
		result = max(result, broken);
		return;
	}

	if(hp[k] <= 0 || broken == N-1){
		func(k+1);
		return;
	}

	for(int i=0; i<N; i++){
		if(k == i || hp[i] <= 0) continue;
		hp[k] -= weight[i];
		hp[i] -= weight[k];
		if(hp[k] <= 0) broken++;
		if(hp[i] <= 0) broken++;
		func(k+1);
		if(hp[k] <= 0) broken--;
		if(hp[i] <= 0) broken--;
		hp[k] += weight[i];
		hp[i] += weight[k];
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for(int i=0; i<N; i++){
		cin >> hp[i] >> weight[i];
	}

	func(0);

	cout << result << "\n";

	return 0;
}

