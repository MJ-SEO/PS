#include<iostream>

using namespace std;

int map[50][50];

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;
		
		int result = 0;
		int middle = n/2;

		for(int i=0; i<n; i++){
			string temp;
			cin >> temp;
			for(int j=0; j<temp.size(); j++){
				map[i][j] = temp[j] - 48;
			}
		}

		for(int i=0; i<=middle; i++){
			for(int j=0; j<n; j++){
					if(j < (middle - i) || j > (middle + i)) continue;
					result += map[i][j];
				}
		}

		int t = 1;
		for(int i=middle+1; i<n; i++){
			for(int j=0; j<n-t; j++){
				if(j < (i - middle)) {
						continue;
				}						
				result += map[i][j];
			}
			t++;
		}

		cout << "#" << test_case << " " << result << "\n";
	}
	return 0;
}