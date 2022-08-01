#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int ball = 0;
		string input;
		cin >> input;

		char prev = input[0];

		for(int i=1; i<input.length(); i++){
			if(input[i] == '.'){
				prev = '.';
			}
			else if(input[i] == '|'){
				if (prev == '('){
					ball++;
				}
				prev = '|';
			}
			else if(input[i] == '('){
				prev = '(';		
			}
			else if(input[i] == ')'){
				if (prev == '(' || prev == '|'){
					ball++;
				}
				prev = '|';
			}
			else{
				break;
			}
		}

		cout << "#" << test_case << " " << ball << "\n";
	}
	return 0;
}

