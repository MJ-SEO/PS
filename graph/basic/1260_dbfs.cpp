#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

bool visit[1005]; 
vector<int> adj[1005]; 
queue<int> q;

void dfs(int nowV) {
	visit[nowV] = true; 
	cout << nowV << " ";
	for (int adjV : adj[nowV]) { 
		if (!visit[adjV]) {
			dfs(adjV); 
		}
	}
}

void bfs(int nowV) {
	q.push(nowV); 
	visit[nowV] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop(); 
		cout << x << " ";
		for (int adjV : adj[x]) {
			if (!visit[adjV]) {
				q.push(adjV); 
				visit[adjV] = true;
			}
		}
	}
}

int main() {
	int numV, numE, startV;
	int temp1, temp2;

	cin >> numV;
	cin >> numE;
	cin >> startV;

	for (int i = 0; i < numE; i++) {
		cin >> temp1 >> temp2;
		adj[temp1].push_back(temp2);
		adj[temp2].push_back(temp1);
	}

	for (int i = 1; i <= numV; i++) {
		sort(adj[i].begin(), adj[i].end());
	}
	dfs(startV);
	cout << "\n";
	memset(visit, 0, sizeof(visit)); //visit배열을 초기화
	bfs(startV);

	return 0;
}
