#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int d[32];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	d[1] = 0;
	d[2] = 3;
	
	for(int i=3; i<=n; i++){
		if(i%2 == 1){
			d[i] = 0;
		}
		else{
			d[i] = d[i-2] * d[i-2];
		}
	}
/*	
	for(int i=0; i<=n; i++){
		cout << d[n] << " ";
	}
	cout << "\n";
*/
	cout << d[n] << "\n";
	return 0;
}

