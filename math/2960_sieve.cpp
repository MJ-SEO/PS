#include <iostream>
#include <vector>

using namespace std;


vector<bool> check(1001, true);
int answer[1001];

int N, K;

int sieve(int n){
    int count = 0;

    for(int i=2; i <=n; i++){
        for(int j=i; j<=n; j+=i){
            if(!check[j]) continue;
            count++;
            check[j] = false;
            answer[count] = j;
        }
    }

    return count;
}

int main(){
    cin.tie();

    cin >> N >> K ;
    
    sieve(N);

    cout << answer[K] << "\n";
}