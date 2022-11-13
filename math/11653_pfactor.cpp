#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    cin.tie(0);

    int n;
    cin >> n;

    if(n==1) return 0;

    for(int i=2; i*i <=n; ){
        if(n%i == 0){
            cout << i << "\n";
            n = n/i;
        }
        else{
            i++;
        }
    }

    cout << n << "\n";

    return 0;
}