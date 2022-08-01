#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int map[9][9];
int dup_map[9][9];
int N, M;
int safety = 0;
queue<pair<int,int>> que;
vector<tuple<int, int, int>> comb;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int count_safety(){
	int count = 0;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			if(dup_map[i][j] == 0) count++;
		}
	}
	return count;
}

void combination(vector<int> cand_list, int n, int r, int index, int target, int comb_arr[]){
	if(r == 0){
		comb.push_back(make_tuple(comb_arr[0], comb_arr[1], comb_arr[2]));
	}
	else if(target == n){
		return;
	}
	else{
		comb_arr[index] = cand_list[target];
		combination(cand_list, n, r-1, index+1, target + 1, comb_arr);
		combination(cand_list, n, r, index, target + 1, comb_arr);
		/*
			combination(arr, souldeSelect-1, index+1);
			combination(arr, souldeSelect, index+1);
		*/
	}
}

void get_combination(){
	vector<int> candidate_list;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			if(map[i][j] == 0){
				candidate_list.push_back(j + M*(i-1));
			}
		}
	}
/*	for(int i=0; i<candidate_list.size(); i++){
		cout << "[CAND] " << candidate_list[i] << " ";
		cout << "\n";
	}
*/
	int c_size = candidate_list.size();

	int* comb_arr = new int[c_size];
	combination(candidate_list, c_size, 3, 0, 0, comb_arr);
}

void map_set(int trial){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			dup_map[i][j] = map[i][j];

			if(map[i][j] == 2){
				que.push({i,j});
			}

			if(get<0>(comb[trial]) == (j + M*(i-1))){
				dup_map[i][j] = 1;
			}
			if(get<1>(comb[trial]) == (j + M*(i-1))){
				dup_map[i][j] = 1;
			}
			if(get<2>(comb[trial]) == (j + M*(i-1))){
				dup_map[i][j] = 1;
			}
		}
	}
}

int map_reset(){
	int count = 0;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			if(dup_map[i][j] == 0) count++;
			dup_map[i][j] = 0;
		}
	}

	return count;
}

void BFS(){
	while(!que.empty()){
		pair<int, int> curr = que.front(); que.pop();

		for(int i=0; i<4; i++){
			int x = curr.first + dx[i];
			int y = curr.second + dy[i];

			if(x < 1 || y < 1 || x > N || y > M) continue;
			if(dup_map[x][y] == 1 || dup_map[x][y] == 2) continue;

			dup_map[x][y] = 2;
			que.push({x,y});
		}
	}
}

void solve(){
	get_combination();

	for(int i=0; i<comb.size(); i++){
		map_set(i);
		BFS();
		safety = max(map_reset(), safety);
	}

	cout << safety << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			cin >> map[i][j];
		}
	}

	solve();

	return 0;
}

