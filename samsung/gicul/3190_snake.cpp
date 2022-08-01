#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <queue>

using namespace std;

int map[101][101];
int tail[101][101];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

char dir[10001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	for(int i=0; i<K; i++){
		int col, row;
		cin >> col >> row;
		map[col][row] = 1;
	}

	int L;
	cin >> L;

	for (int i = 0; i < L; i++)
	{
		int sec;
		char direction;
		cin >> sec >> direction;
		dir[sec] = direction;
	}

	queue<pair<int, int>> snake;

	snake.push({1,1});
	tail[1][1] = 1;

	int result = 0;

	int now_dir = 0;

	while(1){
		result++;

		int next_col = snake.back().first + dy[now_dir];
		int next_row = snake.back().second + dx[now_dir];

		if (next_col < 1 || next_col > N || next_row < 1 || next_row > N) break;

		snake.push({ next_col,next_row });

		if (dir[result] == 'D')
		{
			now_dir += 1;
			if (now_dir == 4) now_dir = 0;
		}

		else if (dir[result] == 'L')
		{
			now_dir -= 1;
			if (now_dir == -1) now_dir = 3;
		}

		if (map[next_col][next_row] == 1)
		{
			map[next_col][next_row] = 0;
		}
		else
		{
			if (tail[next_col][next_row] == 1) break;
			tail[snake.front().first][snake.front().second] = 0;
			snake.pop();
		}

	
		if (tail[next_col][next_row] == true) break;
		else tail[next_col][next_row] = true;
	}

	cout << result << endl;

	return 0;
}
