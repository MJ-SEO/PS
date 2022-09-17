#include <iostream>

using namespace std;

int map[130][130];

int white;
int blue;

void func(int y, int x, int size){
	
	int flag = map[y][x];

	for(int i=y; i< y+size; i++){	
		for(int j = x; j< x+size; j++){
			if(flag == 0 && map[i][j] == 1){
				flag = 2;
			}
			else if(flag == 1 && map[i][j] == 0){
				flag = 2;
			}
			if(flag == 2){
				func(y, x, size/2);
				func(y, x + size/2, size/2);
				func(y + size/2, x, size/2);
				func(y + size/2, x + size/2, size/2);
				return;
			}
		}
	}

	if(flag == 0){
		white++;
	}
	else{
		blue++;
	}
}


int main(){
	int n;
	cin >> n;

	for(int i=0; i<130; i++){
		for(int j=0; j<130; j++){
			map[i][j] = 2;
		}
	}

	for(int i=0; i<n; i++){	
		for(int j=0; j<n; j++){
			scanf("%d", &map[i][j]);
		}
	}

	func(0, 0, n);

	cout << white << "\n" << blue << "\n";
	return 0;
}
