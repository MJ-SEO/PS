#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solutions[100005];
int N;
int res;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	
	for(int i=0; i<N; i++){
		cin >> solutions[i];
	}
	
	int left = 0;
	int right = N - 1;
	res = solutions[left] + solutions[right];

	while (left < right) {
		int temp = solutions[left] + solutions[right];

		if (temp == 0) {
			res = temp;
			break;
		}

		if (abs(temp) < abs(res)) {
			res = temp;
		}
		
		if (temp < 0) {
			left++;
		}
		else {
			right--;
		}
	}

	cout << res << "\n";
	return 0;
}

