#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    int result = 2100000000;

    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    sort(arr, arr+N);

    for(int i=0; i<N; i++){
        int temp = lower_bound(arr, arr+N, M+arr[i]) - arr ;

        if(temp == N) continue;

        result = min(arr[temp] - arr[i], result);
    }
    
    cout << result << "\n";

    return 0;
}
