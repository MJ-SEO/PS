#include <iostream>

using namespace std;

int map[2200][2200];

int zero;
int one;
int m_one;

void func(int x, int y, int size){
	
	int flag = map[x][y];

	for(int i=x; i< x+size; i++){	
		for(int j = y; j< y+size; j++){
			if(flag == 0 && map[i][j] != 0){
				flag = 2;
			
			}
			else if(flag == 1 && map[i][j] != 1){
				flag = 2;
			
			}
			else if(flag == -1 && map[i][j] != -1){
				flag = 2;
			}

			if(flag == 2){
				func(x, y, size/3);
				func(x, y + size/3, size/3);
				func(x, y + (size/3)*2, size/3);
				func(x + size/3, y, size/3);
				func(x + size/3, y + size/3, size/3);
				func(x + size/3, y + (size/3)*2, size/3);
				func(x + (size/3)*2, y, size/3);
				func(x + (size/3)*2, y + size/3, size/3);
				func(x + (size/3)*2, y + (size/3)*2, size/3);
				return;
			}
		}
	}

	if(flag == 0){
		zero++;
	}
	else if(flag == 1){
		one++;
	}
	else{
		m_one++;
	}
}


int main(){
	int n;
	cin >> n;

	for(int i=0; i<n; i++){	
		for(int j=0; j<n; j++){
			scanf("%d", &map[i][j]);
		}
	}

	func(0, 0, n);

	cout << m_one << "\n" << zero << "\n" << one;
	return 0;
}
