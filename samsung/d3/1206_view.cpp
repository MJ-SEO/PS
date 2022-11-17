#include<iostream>

using namespace std;

int map[1005][260];


int check(int x, int y){
	if(map[x-2][y] == 0 && map[x-1][y] == 0 && map[x+1][y] == 0 && map[x+2][y] == 0){
		return 1;
	}
	return 0;
}

void reset(int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<255; j++){
			map[i][j] = 0;
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;

	for(test_case = 1; test_case <= 10; ++test_case){
		int N;
		cin >> N;
		
		int view = 0;
		
		for(int i=0; i<N; i++){
			int height;
			cin >> height;
			for(int j=0; j<height; j++){
				map[i][j] = 1;
			}
		}

		for(int i=2; i<N-2; i++){
			for(int j=0; j<255; j++){
				if(map[i][j] == 0) {
					break;
				}
				if(check(i, j)){
					view++;
				}
			}
		}

		reset(N);

		cout << "#" << test_case << " " << view << "\n";	
	}

	return 0;
}