#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <stdlib.h>

using namespace std;
#define ll long long
#define div 1000000007

int Minute;

ll map[8][8];
ll temp[8][8];
ll origin[8][8] = {
				{0, 1, 1, 0, 0, 0, 0, 0},
				{1, 0, 1, 1, 0, 0, 0, 0},
				{1, 1, 0, 1, 1, 0, 0, 0},
				{0, 1, 1, 0, 1, 1, 0, 0},
				{0, 0, 1, 1, 0, 1, 0, 1},
				{0, 0, 0, 1, 1, 0, 1, 0},
				{0, 0, 0, 0, 0, 1, 0, 1},
				{0, 0, 0, 0, 1, 0, 1, 0},
};

int matrix(int row, int col){
	int sum = 0;
	for(int i=0; i<8; i++){
		sum += (temp[row][i] * origin[i][col]);
	}
	return sum;
}

void m_multi(ll dest[8][8], ll ori[8][8]){
	
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			temp[i][j] = dest[i][j];
		}
	}

	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			dest[i][j] = matrix(i, j) % div;
		}
	}
}

void show_map(){
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> Minute;

	memcpy(map, origin, sizeof(origin));

	which(Minute){
		
		m_multi(map, origin);

	}

	cout << map[0][0] << "\n";

	return 0;
}

