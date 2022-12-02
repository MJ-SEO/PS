#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int N;
stack<int> tower_st;
stack<pair<int, int>> temp_st;

int result[500005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for(int i=0; i<N; i++){
		int t;
		cin >> t;
		tower_st.push(t);
	}

	while(!tower_st.empty()){
		int temp = tower_st.top(); tower_st.pop();

		temp_st.push({temp, tower_st.size()});

		if(tower_st.empty()) break;	

		while(!temp_st.empty() && temp_st.top().first <= tower_st.top()){ 
				result[temp_st.top().second] = tower_st.size(); 
				temp_st.pop();
		}
	}

	for(int i=0; i<N; i++){
		cout << result[i] << " ";
	}
	cout << "\n";

	return 0;
}