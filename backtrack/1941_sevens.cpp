#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char map[5][5];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	for(int i=0; i<5; i++){
		string temp;
		cin >> temp;
		for(int j=0; j<5; j++){
			map[i][j] = temp[j];
		}
	}

	return 0;
}

