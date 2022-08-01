#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int N;
int map[101][101];
int square = 0;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
// 우, 상, 좌, 하

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int x, y, d, g;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x >> y >> d >> g;
		vector<int> dir;
		dir.push_back(d);
		cout << "[DEBUG] " << d << "\n";
		for (int n = 1; n <= g; n++) {
			for (int j = dir.size()-1; j >= 0; j--) {
				dir.push_back((dir[j] + 1) % 4);
				cout << "[DEBUG2] [" << n << "]   " << ((dir[j] + 1) % 4) << "\n";
			}
		}

		map[y][x] = 1;
		for (int k = 0; k < dir.size(); k++) {
			y = y + dy[dir[k]];
			x = x + dx[dir[k]];
			map[y][x]++;
		}
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1]) {
				square++;
			}
		}
	}

	cout << square << "\n";
	return 0;
}
