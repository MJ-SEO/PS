#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

int N;
int map[105][105];
queue<pair<int, int>> que;
stack<pair<int, int>> stack;

int dx[4] = {1, 0, -1, 0};	
int dy[4] = {0, -1, 0, 1};	// 우 상 좌 하


void curve(int x, int y, int direction, int start, int generation){
	if(start > generation) return;

	que.push({x,y});
	map[x][y] = 1;
	x += dx[direction];
	y += dy[direction];

	que.push({x,y})
	map[x][y] = 1;
	int next_dir = 0;
	if(direction == 0) next_dir = 
	else if(direction == 1) next_dir =
	else if(direction == 2) next_dir = 
	else next_dir = 

	curve(x, y, next_dir, start+1, generation);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	
	for(int i=0; i<N; i++){
		int X, Y, direction, generation;
		cin >> X >> Y >> direction >> generation;
		
		curve(X, Y, direction, 0, generation);
	}

	int square = 0;
	for(int i=0; i<=101; i++){
		for(int j=0; j<=101; j++){
				square++;
		}
	}

	cout << square << "\n";

	return 0;
}

