#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>

int map[105][105];
vector<pii> graph[105];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> ;

	for(int i=0; i<m; i++){
		int start, end, cost;
		cin >> start >> end >> cost;
		graph[start].push_back({cost, end});	
	}

	for(int i=0; i<n-1; i++){
		floyd();
	}

	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}

