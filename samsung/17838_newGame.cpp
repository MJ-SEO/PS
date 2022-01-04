#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

int map[13][13];	// 0: white 1: read 2: blue
int N, K;	
int turn = 0;

int dx[5] = {1000, 1, -1, 0, 0 };
int dy[5] = {1000, 0, 0, -1, 1 };

//vector<tuple<int,int,int>> obj;

vector<tuple<int, int, int, vector<int>>> obj;

int four(){
	return 0;
}

int move(int obj_num, int blue){
	int nx = get<0>(obj[obj_num]) + dx[get<2>(obj[obj_num])]; 
	int ny = get<1>(obj[obj_num]) + dy[get<2>(obj[obj_num])];

	if(nx < 1 || ny < 1 || nx > N || ny > N || map[nx][ny] == 2){
		if(blue == 1) return 0;
		if(get<2>(obj[obj_num]) % 2 == 0){				// 짝
			get<2>(obj[obj_num]) = get<2>(obj[obj_num]) - 1; 	
		}
		else{								// 홀
			get<2>(obj[obj_num]) = get<2>(obj[obj_num]) + 1; 	
		} 
		move(obj_num, 1);
	}

	if(map[nx][ny] == 0){
//		for(int i=0; i < get<3>(obj[obj_num]).size(); i++){
			get<0>(obj[obj_num]) = nx;
			get<1>(obj[obj_num]) = ny;	
			// double
//		}
	}
	else{
		get<0>(obj[obj_num]) = nx;
		get<1>(obj[obj_num]) = ny;
		// swap
	}
	
	return 1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> map[i][j];
		}
	}
	
	for(int i=0; i<K; i++){
		int x, y, dir;
		cin >> x >> y >> dir;
		
		vector<int> top;
		top.push_back(i);

		obj.push_back(make_tuple(x, y, dir, top));
	}
	
	/*
	while(1){
		
		for(int i=0; i<K; i++){
			move(i, 0);
		}

		if(four()) break;
		if(turn > 1000) break;
		// loop

		turn++;
	}
	*/

	cout << turn << "\n";
	return 0;
}

