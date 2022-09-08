#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <tuple>

using namespace std;
#define X first
#define Y second


int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int map[1004][1004];
int dist[1004][1004];

int N, M;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	cin.ignore();

	for (int i=0; i<N; i++){
		string temp;
		getline(cin, temp);
		for (int j=0; j<temp.size(); j++){
			map[i][j] = temp[j] - 48;
		}
	}

	queue<pair<int, int>> que;
	que.push({0, 0});
	dist[0][0] = 1;

	while(!que.empty()){
		pair<int, int> curr = que.front(); que.pop();
		for(int i=0; i<4; i++){
			int x = curr.first + dx[i];
			int y = curr.second + dy[i];

			if(x < 0 || y < 0 || x >= N || y >= M) continue;
			if(dist[x][y] >= 1) continue;

		}
	}

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	

	return 0;
}
