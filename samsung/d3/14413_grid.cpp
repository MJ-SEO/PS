#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

char map[51][51];
char visited[51][51];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int possible = 1;
		int N, M;
		cin >> N >> M;

		for(int i=0; i<N; i++){
			string wall;
			cin >> wall;
			for(int j=0; j<M; j++){
				map[i][j] = wall[j];
				visited[i][j] = 0;
			}
		}

		queue<pair<int, int>> que;
		que.push({0,0});
		visited[0][0] = 1;

		while(!que.empty()){
			
			if (possible == 0){
				break;
			}

			pair<int, int> curr = que.front(); que.pop();

			for(int i=0; i<4; i++){
				int x = curr.first + dx[i];
				int y = curr.second + dy[i];

				if (x < 0 || x >= N || y < 0 || y >= M) continue;
				if (visited[x][y] == 1) continue;

				
				if (map[x][y] == '#'){
					if (map[curr.first][curr.second] == '#'){
						possible = 0;
					}
 				}
				else if (map[x][y] == '.'){
					if (map[curr.first][curr.second] == '.'){
						possible = 0;
					}
				}
				else if (map[x][y] == '?'){
					if (map[curr.first][curr.second] == '#'){
						map[x][y] = '.';
					}
					else if (map[curr.first][curr.second] == '.'){
						map[x][y] = '#';
					}
				}

				que.push({x,y});
				visited[x][y] = 1;
			}
		}

		if(possible == 1){
			cout << "#" << test_case << " " << "possible" << "\n";
		}
		else{
			cout << "#" << test_case << " " << "impossible" << "\n";
		}
	}
	return 0;
}

