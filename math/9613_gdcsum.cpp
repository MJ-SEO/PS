#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int gcd(int a, int b){
	if((a%b) == 0 ) return b;

	return gcd(b, a%b);
}

int main(){
        ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for(int i=0; i<t; i++){
		long res = 0;
		int n;
		cin >> n;
		int arr[n];
		for(int j=0; j<n; j++){
			cin >> arr[j];		
		}
		for(int j=0; j<n-1; j++){
			for(int k=j+1; k<n; k++){
				res += gcd(arr[j],arr[k]);
			}
		}
		cout << res << "\n";
	}

        return 0;
}
