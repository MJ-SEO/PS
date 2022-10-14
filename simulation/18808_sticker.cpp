#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, K;
int sticker[101][11][11];
int map[45][45];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;

	for(int i=0; i<K; i++){
		int row, col;
		cin >> row >> col;
		for(int r = 0; r < row; r++){
			for(int c = 0 ; c < col; c++){
				cin >> sticker[i][r][c];
			}
		}
	}

	


	return 0;
}

