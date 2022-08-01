#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int price[1000001];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int test_case;
	int T;

	cin >> T;

	for(test_case = 1; test_case <= T; ++test_case){
		int N;
		cin >> N;
		
		long profit = 0;
		int selling = 1;

		for (int i=0; i<N; i++){
			cin >> price[i];
		}

		for (int i=N-1; i>=0; i=i-selling){
			selling = 1;
			for (int j=i-1; j>=0; j--){
				if (price[j] < price[i]){
					profit += price[i] - price[j];
					selling++;
					cout << "profit " << i  << " " << price[i] - price[j] << "\n";
				}
				else{
					break;
				}
			}
		}

		cout << "#" << test_case << " " << profit << "\n";
	}
	return 0;
}