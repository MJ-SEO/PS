#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int solutions[100001];
int A, B;

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> solutions[i];
	}

	int left = 0;
	int right = N - 1;
	
	int answer = abs(solutions[left] + solutions[right]);
	A = solutions[left];
	B = solutions[right];

	while (left < right) {
		int temp = solutions[left] + solutions[right];
		
		if (temp == 0) break;

		if (abs(temp) < answer) {
			answer = abs(temp);
			A = solutions[left];
			B = solutions[right];
		}

		if (temp < 0) {
			left++;
		}
		else {
			right--;
		}
	}

	cout << A << " " << B << "\n";
}
