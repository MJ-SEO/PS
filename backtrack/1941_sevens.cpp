#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char map[5][5];
bool visited[5][5];
int dx[4] = {1, -1, 0 , 0};
int dy[4] = {0, 0, 1, -1};

int answer;
int cnt_lee;

int count(){
	int t = 0;
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			if(visited[i][j]) t++;	
		}
	}
	return t;
}

void solve(int k, int x, int y){
	if(x < 0 || x > 4 || y < 0 || y > 4 || visited[x][y]){
		return;
	}

	if(k == 6){
		if(map[x][y] == 'S') cnt_lee++;
//		cout << "DEBUG " << k << " " << x << " " << y << " " << cnt_lee << "\n";
		if(cnt_lee >= 4){
			answer++;
		}
		if(map[x][y] == 'S') cnt_lee--;
		return;
	}

//	cout << k << " " << x << " " << y << " " << cnt_lee << "\n";

	for(int dir=0; dir<4; dir++){
		if(map[x][y] == 'S') cnt_lee++;
		visited[x][y] = 1;
		solve(k+1, x+dx[dir], y+dy[dir]);
		visited[x][y] = 0;					
		if(map[x][y] == 'S') cnt_lee--;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	for(int i=0; i<5; i++){
		string temp;
		cin >> temp;
		for(int j=0; j<5; j++){
			map[i][j] = temp[j];
		}
	}

//	for(int i=0; i<5; i++){
//		for(int j=0; j<5; j++){
			solve(0, 1, 0);
//		}
//	}

	cout << answer << "\n";

	return 0;
}

