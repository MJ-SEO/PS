#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

vector<int> graph[32001];
int list[32001];
	
int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	priority_queue<int, vector<int>, greater<int>> que;
	vector<int> result;

	for(int i=0; i<m; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		list[b] += 1;
	}	

	for(int i=1; i<=n; i++){
		if(list[i] == 0){
			que.push(i);
		}
	}
	
	while(!que.empty()){
		int t = que.top(); que.pop();
		result.push_back(t);
		
		cout << t << " ";
		
		for(int i=0; i<graph[t].size(); i++){
			int nxt = graph[t][i];
			list[nxt]--;
			if(list[nxt] == 0){	
				que.push(nxt);
			}
		}
	}


	for(int i=0; i<n; i++){
		cout << result[i] << " ";
	}

        return 0;
}

