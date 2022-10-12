#include <iostream>

using namespace std;

int N, S;
int result;
int store[25];

void func(int cur, int sum){
    if(cur == N){
        if(sum == S){
            result++;
        }
        return;
    }

    func(cur+1, sum);
    func(cur+1, sum+store[cur]);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;

    for(int i=0; i<N; i++){
        cin >> store[i];
    }

    func(0, 0);
  
    if(S == 0) result--;
    cout << result << "\n";
}