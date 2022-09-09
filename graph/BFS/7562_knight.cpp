#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

#define X first
#define Y second

int map[301][301];
int turn[301][301]; 
int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[8] = {2, -2, 1, -1, 2, -2, 1, -1};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for(int i=0; i<T; i++){
		int length;
		cin >> length;

		for(int i=0; i<length; i++){
			for(int j=0; j<length; j++){
				turn[i][j] = -1;
			}
		}

		pair<int, int> start, dest;
		cin >> start.first >> start.second;
		cin >> dest.first >> dest.second;		

		queue<pair<int, int>> que;
		que.push({start.first, start.second});
		turn[start.first][start.second] = 0;

		int end_flag = 0;

		while(!que.empty()){
			if(end_flag == 1) break;
			pair<int, int> cur = que.front(); que.pop();

			for(int j=0; j<8; j++){
				int nx = cur.first + dx[j];
				int ny = cur.second + dy[j];

/*				if(nx == dest.first && ny == dest.second){
					end_flag = 1;
					break;
				}
*/
				if(nx < 0 || ny < 0 || nx >= length || ny >= length) continue;
				if(turn[nx][ny] >= 0) continue;

				que.push({nx, ny});
				turn[nx][ny] = turn[cur.first][cur.second] + 1;
			}
		}

		cout << turn[dest.first][dest.second] << "\n";
	}
	
	return 0;
}
