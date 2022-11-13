#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    cin.tie(0); 
    int n, k;
    cin >> n >> k;

    int result = 1;

    for(int i=n; i>1; i--){
        result *= i;
    }

    for(int i=n-k; i>1; i--){
        result /= i;
    }

    for(int i=k; i>1; i--){
        result /= i;
    }

    cout << result << "\n";

    return 0;
}