#include <iostream>

using namespace std;

int map[2200][2200];

int zero;
int mone;
int pone;

int check(int x, int y, int size){			// 3^N size의 map이 전부 같은 종이인지 check
	int flag = map[x][y];
	for(int i=x; i < (size + x); i++){
		for(int j=y; j < (size + y); j++){
			if(map[i][j] != flag){	 // flag for distinguish
				return 2;
			}
		}
	}
	return flag;
}

void func(int x, int y, int size){
	if(size == 0){	// base condition
		return;
	}

	int color = check(x, y, size);
	if(color == -1){	// counting number
		mone++;
	}
	else if(color == 0){
		zero++;
	}
	else if(color == 1){
		pone++;
	}
	else{		// recursive function
		int scalar = size/3;
		func(x, y, scalar);
		func(x + scalar, y, scalar);
		func(x + 2*scalar, y, scalar);
	
		func(x, y + scalar, scalar);
		func(x + scalar, y + scalar, scalar);
		func(x + 2*scalar, y + scalar, scalar);

		func(x, y + 2*scalar, scalar);
		func(x + scalar, y + 2*scalar, scalar);
		func(x + 2*scalar, y + 2*scalar, scalar);
	}
}


int main(){
	int n;
	cin >> n;

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> map[i][j];
		}
	}         

	func(0, 0, n);      

	cout << mone << "\n" << zero << "\n" << pone << "\n";

	return 0;
}
