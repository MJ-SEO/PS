#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstring>

using namespace std;

int main(){
	int size = 100000;

	clock_t start = clock();

	short** c = (short**)malloc(sizeof(short*) * size + 2);
	for (int i=0; i<size+2; i++){
		c[i] = new short[size+2];
//		c[i] = (short*)malloc(sizeof(short) * size + 2);
		memset(c[i], 0, sizeof(short) * (size+2));
	}

	clock_t end = clock();

	printf("time is %12.10f\n", ((float)(end-start) / CLOCKS_PER_SEC)*1000000);
	return 0;
}

