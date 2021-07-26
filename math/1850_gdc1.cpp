#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long gcd(long long a, long long b){
	if (a % b == 0) return b; 
	
	return gcd(b, a%b);
}


int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);

        long long a, b, res;
        cin >> a >> b;

        res = gcd(a,b);
    
	cout << "[DEBUG] " << res << " " << "\n";

	for(int i=0; i<res; i++){
		cout << 1;
	}
	cout << "\n";

        return 0;
}
