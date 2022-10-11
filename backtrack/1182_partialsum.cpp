#include <iostream>

using namespace std;

int N, S;
int result;

int store[25];
bool isused[25];

void func(int k){
    if(k == S){
        result++;
        return;
    }

    for(int i=0; i<N; i++){
        if(!isused[i]){
            isused[i] = 1;
            k += store[i];
            func(k);
            isused[i] = 0;
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;

    for(int i=0; i<N; i++){
        cin >> store[i];
    }

    func(0);

    cout << result << "\n";
}