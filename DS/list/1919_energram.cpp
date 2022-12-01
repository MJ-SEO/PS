#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a_ascii[27];
int b_ascii[27];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a, b;
	cin >> a >> b;

	int cnt = 0;

	for(auto e : a){
		a_ascii[e-97]++;
	}

	for(auto e : b){
		b_ascii[e-97]++;
	}

	for(int i=0; i<27; i++){
		if(a_ascii[i] == b_ascii[i]) continue;

		while(a_ascii[i] > b_ascii[i]){
			a_ascii[i]--;
			cnt++;
		}
		
		while(b_ascii[i] > a_ascii[i]){
			b_ascii[i]--;
			cnt++;
		}
	}

	cout << cnt << "\n";
	return 0;
}

