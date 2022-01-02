#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[1000005];

int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);

	int n;
	cin >> n;

	for(int i=0; i<n; i++){
		int temp;
		cin >> temp;
		arr[temp] = arr[temp] + 1;
	}
	
	for(int i=0; i<=1000005; i++){
		while(arr[i]--){
			cout << i << "\n";
		}
	}

        return 0;
}

