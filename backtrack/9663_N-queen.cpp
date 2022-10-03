#include <iostream>

using namespace std;

int result = 0;
int n;
bool isused[15][15];

bool isvalid(int i, int k){
	int x, y;
	for(x = 0; x<n; x++){
		if(isused[i][x]) return 0;
	}

	for(x = k-1, y = i-1; y>=0; x--, y--){
		if(isused[y][x]) return 0;
	}

	for(x = k-1, y = i+1; y < n; x--, y++){
		if(isused[y][x]) return 0;
	}
	
	return 1;
}

void func(int k){
	if(k==n){
		result++;
		return;
	}
	for(int i=0; i<n; i++){
		if(!isused[i][k] && isvalid(i, k)){
			isused[i][k] = 1;
			func(k+1);
			isused[i][k] = 0;
		}
	}
}

int main(){
	cin >> n;
	func(0);
	cout << result << "\n";
	
	return 0;
}
