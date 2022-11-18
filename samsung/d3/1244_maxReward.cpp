#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>

using namespace std;

int get_cnum(vector<int> arr){
	int num = 0;
	for(int i=0; i<arr.size(); i++){
		num += arr[i] * (int)pow(10, arr.size()-i-1); 
	}
	return num;
}

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

		int max_reward = 0;

		while(num){
			reward.push_back(num%10);
			num = num/10;
		}
		reverse(reward.begin(), reward.end());
	
		while(change--){

			for(int i=0; i<reward.size()-1; i++){
				for(int j=i+1; j<reward.size(); j++){
					swap(reward[i], reward[j]);
					int changed_num = get_cnum(reward);
					max_reward = max(max_reward, changed_num);
					swap(reward[j], reward[i]);
				}
			}

//			cout << "DEBUG " << max_reward << "\n";

			if(change == 0) break;
			
			reward.clear();
			while(max_reward){
				reward.push_back(max_reward%10);
				max_reward = max_reward/10;
			}
		}

		cout << "#" << test_case << " " << max_reward << "\n";		
	}

	return 0;
}

