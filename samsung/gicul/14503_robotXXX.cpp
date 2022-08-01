#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int map[51][51];
int visited[51][51];
queue<pair<int, int>> que;
int cleand;

int dx[4] = {0, };
int dy[4] = {-1, };

int N, M, r, c, d;

// 0 북쪽 1 동쪽 2 남쪽 3 서쪽

void BFS(){
	while(!que.empty()){
		pair<int, int> cur = que.front(); que.pop();

		if(d==0){
			
		}

		for(int i=0; i<4; i++){
			int x = cur.first + dx[i];
			int y = cur.second + dy[i];

			if() continue;
			if() continue;


		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	cin >> r >> c >> d;

	que.push({r, c}); cleand++;

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> map[i][j];
		}
	}

	for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				cout << map[i][j] << " ";
			}
			cout << "\n";
	}

	BFS();

	cout << cleand << "\n";
	return 0;
}

