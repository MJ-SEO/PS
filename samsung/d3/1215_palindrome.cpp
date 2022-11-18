#include<iostream>

using namespace std;

char map[9][9];

bool row_palin(int x, int y, int length){
	for(int i=0; i<length/2; i++){
		if(map[x][y+i] != map[x][y+length-i-1]) return false;
	}
	return true;
}

bool col_palin(int x, int y, int length){
	for(int i=0; i<length/2; i++){
		if(map[x+i][y] != map[x+length-i-1][y]) return false;
	}
	return true;
}


int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int p_len;
		cin >> p_len;
		int palindrome = 0;

		for(int i=0; i<8; i++){
			string temp;
			cin >> temp;
			for(int j=0; j<8; j++){
				map[i][j] = temp[j];
			}
		}

		for(int i=0; i<8; i++){
			for(int j=0; j<=8-p_len; j++){
				if(row_palin(i, j, p_len)) {
					palindrome++;
				}
			}
		}

		for(int i=0; i<=8-p_len; i++){
			for(int j=0; j<8; j++){
				if(col_palin(i, j, p_len)) palindrome++;
			}
		}

		cout << "#" << test_case << " " << palindrome << "\n";
	}
	return 0;
}