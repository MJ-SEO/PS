#include <iostream>

using namespace std;

bool star[10000][10000];

void func(int n, int x, int y){
	if (n == 3) {
		star[x][y] = true;
		star[x + 1][y - 1] = true;
		star[x + 1][y + 1] = true;
		for (int i = 0; i < 5; i++) {
			star[x + 2][y - i + 2] = true;
		}
		return;
	}

	func(n / 2, x, y);
	func(n / 2, x + n / 2, y - n/2 );
	func(n / 2, x + n / 2, y+n/2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    	int num;
    	cin >> num;

    	for(int i = 0; i < num; i++){
    	    for(int j = 0; j < num*2-1; j++){
    	        star[i][j] = false;
	    }
    	}

	func(num, 0, num-1);

    	for(int i = 0; i < num; i++){
    	    for(int j = 0; j < num*2-1; j++){
    	        if(star[i][j]){
			cout << "*";
		}
		else{
			cout << " ";
		}
	    }
	    cout << "\n";
    	}

}
