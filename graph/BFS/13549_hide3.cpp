#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, K;
int map[200005];
int dist[200005];

queue<int> que;

void bfs(){

	while(!que.empty()){
		int cur = que.front(); que.pop();
		if(cur == K) {
			break;
		}

		for(int i=0; i<3; i++){
			int nxt;
			if(i == 0)	nxt = cur - 1;
			else if(i == 1) nxt = cur + 1;
			else if(i == 2) nxt = cur * 2;
			
			if(nxt < 0 || nxt > 100005) continue;
			if(dist[nxt] >= 0) continue;

			que.push(nxt);

			if(i==2) dist[nxt] = dist[cur];
			else dist[nxt] = dist[cur] + 1;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	for(int i=0; i<100005; i++) dist[i] = -1;

	que.push(N);
	dist[N] = 0;

	bfs();

	cout << dist[K] << "\n";
	return 0;
}


/* TODO D*/