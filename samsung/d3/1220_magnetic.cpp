#include<iostream>

using namespace std;

int map[101][101];

int main(int argc, char** argv)
{
	int test_case;

	for(test_case = 1; test_case <= T10; ++test_case)
	{	
		int n;
		cin >> n;
		int result = 0;

		for(int i=0; i<100; i++){
			for(int j=0; j<100; j++){
				cin >> map[i][j];
			}
		}

		for(int i=0; i<100; i++){
			int flag = 0;
			for(int j=0; <100; j++){
				if(map[i][j] == 1) flag = 1;
				if(map[j][i] == 2 && flag ==1) {
					result++;
					flag = 0;
				}
			}
		}

		cout << "#" << test_case << " " << result << "\n";
	}
	return 0;
}