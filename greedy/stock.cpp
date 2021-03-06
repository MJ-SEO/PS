#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(int a, int b){
	return a > b;
}

int arr[1000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for(int i=0; i<n; i++){
		int t;
		cin >> t;
		vector<int> max_arr;
		long long result = 0;

		for(int j=0; j<t; j++){
			int temp;
			cin >> temp;
			max_arr.push_back(temp);
			arr[j] = temp;
		}

		sort(max_arr.begin(), max_arr.end(), cmp);

		int checker = 0;
		for(int k=0; k<t; k++){
			if(arr[k] == max_arr[checker]) {
				checker++;
				continue;
			}
			result += max_arr[checker] - arr[k];

		}
		
		cout << result << "\n";
	}

	return 0;
}
