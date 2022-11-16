#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int arr[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    int st = 0;
    int en = 0;
    int prefix_sum = arr[0];
    int shortest_len = 100001;

    for(int st=0; st<N; st++){  
        while(prefix_sum < M && en < N){
            en += 1;   
            if(en != N) prefix_sum += arr[en];
        }
        if(en == N) break;

        shortest_len = min(shortest_len, en-st+1);
        prefix_sum -= arr[st];
    }

    if(shortest_len == 100001) shortest_len = 0;
    cout << shortest_len << "\n";
    return 0;
}