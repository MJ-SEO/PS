#include <iostream>

using namespace std;

char map[65][65];


void func(int x, int y, int size){
	
	char flag = map[x][y];

	for(int i=x; i< x+size; i++){	
		for(int j = y; j< y+size; j++){
			if(flag == '0' && map[i][j] == '1'){
				flag = '2';
			}
			else if(flag == '1' && map[i][j] == '0'){
				flag = '2';
			}
			if(flag == '2'){
				cout << "(";
				func(x, y,  size/2);
				func(x, y + size/2, size/2);
				func(x + size/2, y, size/2);
				func(x + size/2, y + size/2, size/2);
				cout << ")";
				return;
			}
		}
	}
	if(flag == '0'){
		cout << "0";
	}
	else{
		cout << "1";
	}
}


int main(){
	int n;
	cin >> n;
	char buf[2];
	scanf("%c", buf);
	
	for(int i=0; i<n; i++){	
		for(int j=0; j<n; j++){
			scanf("%c", &map[i][j]);
		}
		scanf("%c", buf);
	}

	func(0, 0, n);

//	cout << white << "\n" << blue << "\n";
	return 0;
}
