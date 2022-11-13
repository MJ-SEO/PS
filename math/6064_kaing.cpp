#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T;

int gcd(int a, int b){
    if(a%b == 0) return b;
    return gcd(b, a%b);
}

int lcm(int a, int b){
    return a / gcd(a, b) * b;
}

int solve(int m, int n, int x, int y){
    int l = lcm(m, n);
    for(int i=x; i<=l; i+=m){
        if((i%n == y) || (y==n && i%n == 0)){
            return i;
        }
    }
    return -1;
}

int main(){
    cin.tie(0);

    cin >> T;

    for(int i=0; i<T; i++){
        int M, N, x, y;
        cin >> M >> N >> x >> y;

        cout << solve(M, N, x, y) << "\n";
    }

    return 0;
}