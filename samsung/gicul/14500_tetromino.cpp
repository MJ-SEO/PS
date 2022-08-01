#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int map[515][515];
int N, M;
int answer;

int dt[5] = {0, 1, 2, 3, 4}
int dx[5][4][4] = { } 
int dy[5][4][4] = ;

int get_sum(int type, int direction, int x, int y){
	int re = 0;
	for(int i=0; i<4; i++){
		re += map[x][y]
	}
	return re;
}

int trial(int x, int y){
	int t_max = 0;
	for(int i=0; i<5; i++){			// five tpyes of tetromino
		for(int j=0; j<4; j++){		// four directions of tetromino
				t_max = max(t_max, get_sum(i, j, x, y));		
		}
	}
	return t_max;
}

void solve(){
	for(int i=5; i<N; i++){
		for(int j=5; j<M; j++){
			answer = max(answer, trial(i, j));
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;

	for(int i=5; i<N; i++){
		for(int j=5; j<M; j++){
			cin >> map[i][j];
		}
	}

	solve();
	
	cout << answer << "\n";

	return 0;
}

