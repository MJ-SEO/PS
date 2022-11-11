#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int max_weight = 0;

    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    sort(arr, arr+N, greater<>());

    for(int i=0; i<N; i++){
        max_weight = max(max_weight, arr[i] * (i+1));
    }

    cout << max_weight << "\n";
}