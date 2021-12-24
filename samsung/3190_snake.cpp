#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int map[101][101];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int result = 0;

	int N, K;
	cin >> N >> K;

	for(int i = 0; i < K; i++){
		int row, col;
		cin >> row >> col;
		map[row][col] = 1;;
	}

	int L;
	cin >> L;

	queue<pair<int, char>> que; 

	for(int i = 0; i < L; i++){
		int second;
		char direction;
		cin >> second >> direction;
		que.push_back
	}

	cout << result << "\n";
	return 0;
}

