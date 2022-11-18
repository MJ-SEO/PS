#include<iostream>

using namespace std;

int map[101][101];

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int tc;
		cin >> tc;

		int max_sum = 0;

		for(int i=0; i<100; i++){
			for(int j=0; j<100; j++){
				cin >> map[i][j];
			}
		}

		// SKIP IT'S TOO EASY

		cout << "#" << tc << " " << max_sum << "\n";	
	}
	return 0;
}