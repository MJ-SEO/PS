#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
		int num, change;
		cin >> num >> change;
		vector<int> reward;

		while(num){
			reward.push_back(num%10);
			num = num/10;
		}

		reverse(reward.begin(), reward.end());
		
		for(int i=0; i<reward.size(); i++){
			cout << reward[i];
		}
		
	}

	return 0;
}

