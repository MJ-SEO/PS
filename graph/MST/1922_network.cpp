#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;
using tp = tuple<int,int,int>;

vector<pair<int, int>> graph[100002];
int list[100002];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;

	for(int i=0; i<m; i++){
		int a, b, weight;
		cin >> a >> b >> weight;
		graph[a].push_back({weight, b});
		graph[b].push_back({weight, a});
	}	
	int count = 0;
	int result = 0;

	priority_queue<tp, vector<tp>, greater<tp>> que;
	for(auto nxt : graph[1]){
		que.push({nxt.first, 1, nxt.second});
//		cout << "DEBUG " << nxt.first << " " << nxt.second << "\n";
	}
	list[1] = 1; // true
	
	while(1){
		int cost, v1, v2;
		tie(cost, v1, v2) = que.top(); que.pop();
		if(list[v2]) continue;
		list[v2] = 1;
		result += cost;
		count++;
		if(count == n-1) break;
		for(auto nxt : graph[v2]){
			if(!list[nxt.second])
				que.push({nxt.first, v2, nxt.second});
		}
	}
	cout << result;

	return 0;
}

