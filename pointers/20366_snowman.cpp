#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int snow[605];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for(int i=0; i<N; i++){
		cin >> snow[i];
	}

	

	return 0;
}

/*

1. 눈사람을 만들 수 있도록 

2. 두 눈사람 간의 키차이가 가장 작도록

@ h는 최대 10억

*/
