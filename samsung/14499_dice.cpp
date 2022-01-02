#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct dice{
	int curr_up;
	int curr_right;

	int upward;
	int downward;
	int up;
	int down;
	int left;
	int right;
} dice_t;

int map[21][21];

int dx[5] = {1000, 0, 0, -1, 1};
int dy[5] = {1000, 1, -1, 0, 0};

void showmap(int a){
	for(int i=0; i<a; i++){
		for(int j=0; j<a; j++){
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}

int range_check(int op, int x, int y, int row_b, int col_b){
	int cur_x = x + dx[op];
	int cur_y = y + dy[op];

	if(cur_x < 0 || cur_x >= row_b || cur_y < 0 || cur_y >= col_b){
		return 1;
	}	
	return 0;
}

void move_dice(int op, int* x, int* y){
	if(op == 1) *y = *y + 1;
	else if(op == 2) *y = *y - 1;
	else if(op == 3) *x = *x - 1;
	else *x = *x + 1;
}

int rolling(int op, int x, int y, dice_t* dice){
	if(op == 1){
		
	}
	else if(op == 2){

	}
	else if(op == 3){

	}
	else{
		if(dice->curr_up == 1){

		}	
	}
	return dice->upward;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M, x, y, K;
	cin >> N >> M >> x >> y >> K;
	
	dice_t dice;
	dice.curr_up = 1;
	dice.curr_right = 3;
	dice.upward = 0;
	dice.downward = 0;
	dice.up = 0;
	dice.down = 0;
	dice.left = 0;
	dice.right = 0;

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> map[i][j];
		}		
	}
	
	for(int i=0; i<K; i++){
		int op;
		cin >> op;
		if(range_check(op, x, y, N, M) == 1) continue;	
		
		cout << rolling(op, x, y, &dice) << "\n";
		move_dice(op, &x, &y);
	}

	return 0;
}

