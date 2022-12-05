#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;
#define X first
#define Y second


int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int map[101][101];
bool visited[101][101];

void clearvisited(int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			visited[i][j] = 0;
		}
	}
}

int main(){
	int mx = 0;
	int n;
	cin >> n;
	cin.clear();

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &map[i][j]);
		}
	}

	for(int k = 0; k< 101; k++){
	clearvisited(n);
	while(!que.empty()){
		que.pop();
	}
	int safe = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(map[i][j] <= k || visited[i][j]) continue;
			safe++;
//			cout << "DEBUG max: " << max << "\n"; 
			visited[i][j] = 1;
			que.push({i,j});

			while(!que.empty()){
				pair<int, int> cur = que.front(); que.pop();

				for(int i=0; i<4; i++){
					int x = cur.X + dx[i];
					int y = cur.Y + dy[i];

					if(x < 0 || x >= n || y < 0 || y >= n) continue;
					if(visited[x][y]) continue;
					if(map[x][y] <= k) continue;

					visited[x][y] = 1;
					que.push({x,y});
				}
			}
		}
	}	
	mx = max(mx, safe);
}

	cout << mx;
	return 0;
}

