#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
long long solutions[5005];
int A, B, C;

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> solutions[i];
	}
	sort(solutions, solutions+N);

	long long answer = 3000000010;

	for(int i=0; i<N-2; i++){
		int left = i+1;
		int right = N-1;

		while (left < right) {
			long long temp = solutions[i] + solutions[left] + solutions[right];

			if (abs(temp) < answer) {
				answer = abs(temp);
				A = solutions[i];
				B = solutions[left];
				C = solutions[right];
			}

			if (temp < 0) {
				left++;
			}
			else {
				right--;
			}
		}
	}

	cout << A << " " << B << " " << C << "\n";
}
