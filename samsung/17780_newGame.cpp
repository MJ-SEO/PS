#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <deque>

using namespace std;

int map[13][13][11];	// 0: white 1: read 2: blue
int N = 0;
int OB = 0;	
int four = 0;
int turn = 1;

int dx[5] = {1000, 0, 0, -1, 1 };
int dy[5] = {1000, 1, -1, 0, 0 };  // 우 좌 상 하

vector<tuple<int, int, int, int, int>> obj; // x, y, direction, floor, obj_num
vector<tuple<int, int, int, int, int>> deck;

// vector<tuple<int, int, int, vector<int>>> obj;

bool compare_g(tuple <int,int,int,int,int> a, tuple <int,int,int,int,int> b){
	return get<3>(a) > get<3>(b);
}

bool compare(tuple <int,int,int,int,int> a, tuple <int,int,int,int,int> b){
	return get<3>(a) < get<3>(b);
}

int search_obj(int x, int y){
	int num_obj = 0;
	for(int i=0; i<OB; i++){
		if(get<0>(obj[i]) == x && get<1>(obj[i]) == y) num_obj++;
	}	
	return num_obj;
}

void sort_curr(int x, int y, int floor, int color){
	for(int i=0; i<OB; i++){
		if(get<0>(obj[i]) == x && get<1>(obj[i]) == y && get<3>(obj[i]) >= floor) deck.push_back(obj[i]);
	}

	if(color == 0){
		sort(deck.begin(), deck.end(), compare);
	}
	else{
		sort(deck.begin(), deck.end(), compare_g);
	}
}

int move(int obj_num, int blue){
	if(get<3>(obj[obj_num]) != 0) return 1;

	int ox = get<0>(obj[obj_num]); 
	int oy = get<1>(obj[obj_num]);
	int of = get<3>(obj[obj_num]);

	int nx = get<0>(obj[obj_num]) + dx[get<2>(obj[obj_num])]; 
	int ny = get<1>(obj[obj_num]) + dy[get<2>(obj[obj_num])];

//	cout << "NX NY " << nx << " " << ny << " " << N << " " << map[nx-1][ny-1][0] << "" "\n";

	if(nx < 1 || ny < 1 || nx > N || ny > N || map[nx-1][ny-1][0] == 2){
		if(blue >= 1) return 0;
//		cout << "BD " << get<2>(obj[obj_num]) << "\n";
		if(get<2>(obj[obj_num]) % 2 == 0){				// Even
			get<2>(obj[obj_num]) = get<2>(obj[obj_num]) - 1; 	
		}
		else{								// Odd
			get<2>(obj[obj_num]) = get<2>(obj[obj_num]) + 1; 	
		}
//		cout << "AD " << get<2>(obj[obj_num]) << "\n";
		move(obj_num, 1);
	}
	else if(map[nx-1][ny-1][0] == 0 || map[nx-1][ny-1][0] == 1 ){	// white
		int new_floor = 0;
		new_floor = search_obj(nx, ny);	// 벽 체크?
		sort_curr(ox, oy, of, map[nx-1][ny-1][0]);
		
//		cout << "DEBUG WR " << new_floor << " " << deck.size() << "\n";
		if(new_floor + deck.size() >= 4) four = 1;

		for(int i=0; i<deck.size(); i++){
			int n_obj = get<4>(deck[i]);

			get<0>(obj[n_obj]) = nx;
			get<1>(obj[n_obj]) = ny;
			get<3>(obj[n_obj]) = new_floor;
			new_floor++;
		}	
		deck.clear();			
	}
	else{
		cout << "nono\n";
	}

	return 1;
}

void show_map(){
	for(int i=0; i<OB; i++){
		cout << "[" << get<3>(obj[i]) << "]" << get<0>(obj[i]) << " " << get<1>(obj[i]) << "\n";
	}
	cout << "=========\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> OB;

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			int temp;
			cin >> temp;
			for(int k=0; k<OB; k++){
				map[i][j][k] = temp;
			}
		}
	}


	for(int i=0; i<OB; i++){
		int x, y, dir;
		cin >> x >> y >> dir;

		int floor = 0;
		//		vector<int> top;
		//		top.push_back(i);
		map[x][y][floor];

		obj.push_back(make_tuple(x, y, dir, floor, i));
	}

	int game_over = 0;
	int error = 0;
	
//	show_map();
	while(1){
		for(int i=0; i<OB; i++){
			move(i, 0);
		//	show_detail();
		//	show_map();
			if(four) game_over = 1;
		}
	//	cout << "========TURN Over========\n";
		if(game_over) break;
		if(turn > 1000) {
			error = 1;
			break;
		}
		// loop

		turn++;
	}

//	cout << "DEBUG turn: " << turn << "\n";

	if(error == 1){
		cout << "-1" << "\n";
	}
	else{
		cout << turn << "\n";
	}
	return 0;
}

