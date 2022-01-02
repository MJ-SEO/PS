#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int gdc(int a, int b){
	while (b != 0) {
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}

int getlcm(int a, int b){
	return a*b/gdc(a,b);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for(int i=0; i<n; i++){
		int a, b, res;
		cin >> a >> b;

		res = getlcm(a,b);

		cout << res << "\n";
	}

	return 0;
}
