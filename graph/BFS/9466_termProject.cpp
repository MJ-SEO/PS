#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
 
int N;
int cnt;

int student[100005];
int visited[100005];
int hasteam[100005];

queue<int> que;

void bfs(int target){
	vector<int> chain;

	while(!que.empty()){
		int cur = que.front(); que.pop();
		chain.push_back(cur);
		
		if(student[cur] == target){
			for(auto e : chain){
				hasteam[e] = 1;
				cnt++;
			}
			break;
		}
		if(visited[student[cur]]) break;

		que.push(student[cur]);
		visited[student[cur]] = 1;
	}

	for(auto e : chain){
		visited[e] = 0;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while(T--){
		cin >> N;
		cnt = 0;

		for(int i=1; i<=N; i++){
			cin >> student[i];
		}

		for(int i=1; i<=N; i++){
			if(hasteam[i] == 1) continue;
			que.push(i);
			visited[i] = 1;
			bfs(i);
		}

		cout << N - cnt << "\n";
		
		for(int i=1; i<=N; i++){
			hasteam[i] = 0;
		}
	}

	return 0;
}

