#include<iostream>

using namespace std;

int map[105][105];
int height[105];

void flatten(){
	int max_idx = 0;
	int min_idx = 0;
	int max_h = -1;
	int min_h = 1000;

	for(int i=0; i<100; i++){
		if(height[i] > max_h){
			max_h = max(max_h, height[i]);
			max_idx = i;
		}

		if(height[i] < min_h){
			min_h = min(min_h, height[i]);
			min_idx = i;
		}	
	}

	height[max_idx]--;
	height[min_idx]++;
}

int main(int argc, char** argv)
{
	int test_case;

	for(test_case = 1; test_case <= 10; ++test_case)
	{
		int dump;
		cin >> dump;

		int max_h = -1;
		int min_h = 1000;

		for(int i=0; i<100; i++){
			cin >> height[i];
/*			int height;
			cin >> height;
			for(int j=0; j<height; j++){
				map[i][j] = 1;
			}
*/
		}
		
		for(int i=0; i<dump; i++){
			flatten();
		}

		for(int i=0; i<100; i++){
			max_h = max(max_h, height[i]);
			min_h = min(min_h, height[i]);
		}

		cout << "#" << test_case << " " << (max_h - min_h) << "\n";	
	}
	return 0;
}