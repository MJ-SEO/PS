#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int check[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	int result = 0;
	int count = 0;
	int end_checker = 100005;

	queue<pair<int, int>> que;
	que.push({n, 0});
	check[n] = 1;

	while(!que.empty()){
		pair<int, int> curr = que.front(); que.pop();
		check[curr.first] = 1;
//	      	cout << "DEBUG " << curr.first << " " << curr.second << "\n";
		if(curr.second > end_checker) break;
		if(curr.first == k){
			result = curr.second;
			count++;
			end_checker = curr.second;
		}
		
		for(int i=0; i<3; i++){
			pair<int ,int> next_step;
			if(i==0){
				next_step.first = curr.first-1;
				next_step.second = curr.second+1;
				if(next_step.first >= 0 && next_step.first <= 100000){
					if(check[next_step.first] == 0 || next_step.first == k){
						que.push({next_step.first, curr.second+1});
					}
				}	
			}
			else if(i==1){
				next_step.first = curr.first+1;
				next_step.second = curr.second+1;
				if(next_step.first >= 0 && next_step.first <= 100000){
					if(check[next_step.first] == 0 || next_step.first == k){
						que.push({next_step.first, curr.second+1});
					}
				}	
			}
			else{
				next_step.first = curr.first*2;
				next_step.second = curr.second+1;
				if(next_step.first >= 0 && next_step.first <= 100000){
					if(check[next_step.first] == 0 || next_step.first == k){
						que.push({next_step.first, curr.second+1});
					}
				}	
			}		
		}
	}
	
	cout << result << "\n" << count << "\n";
	return 0;
}

