#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;
using pii = pair<int, int>;

pii map[6][6];

pii shark;
stack<pii> st_shark;

int dx[9] = {1000, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[9] = {1000, 0, -1, -1, -1, 0, 1, 1, 1};

/*
void DFS(){
	pii temp = st.top(); st.pop();
	
	while(!st.empty()){
		for(int i=0; i<8; i++){
			int nx = ;
			int ny = ;
			
			if(벽) continue;
		}
	}
}
*/

void swap(int source_x, int source_y, int target_x, int target_y, int new_dir){
	int temp_fish = map[target_x][target_y].first;
	int temp_dir = map[target_x][target_y].second;
	
	map[target_x][target_y].first = map[source_x][source_y].first;
	map[target_x][target_y].second = new_dir;

	map[source_x][source_y].first = temp_fish;
	map[source_x][source_y].second = temp_dir;
}

void fish_move(){
	for(int fish=1; fish<=16; fish++){
		int start = 0;
		for(int i=0; i<4; i++){
			if(start == 1) break;
			for(int j=0; j<4; j++){
				if(start == 1) break;
				if(map[i][j].first != fish) continue;
				
				cout << "FISH" << fish << " " << i << " " << j << " " << map[i][j].second << "\n";
				
				for(int k=0; k<8; k++){
					int nx = i + dx[(k + map[i][j].second)%9];
					int ny = j + dy[(k + map[i][j].second)%9];
					cout << "DEBUG " << nx << " " << ny << "\n";

					if(nx < 0 || ny < 0 || nx > 4 || ny > 4) continue;
					if(map[nx][ny].first == 0) continue;

					int new_dir = (map[i][j].second + k)%9;
					swap(i, j, nx, ny, new_dir);
					cout << "[NEXT] FISH" << fish << " " << i << " " << j << " " << nx << " " << ny << " " << new_dir << "\n\n";
					start = 1;
					break;
				}
			}
		}
	}
}


void show_map(int c){
	if(c == 1){
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				cout << map[i][j].first << " ";
			}
			cout << "\n";
		}
	}
	else{
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				cout << map[i][j].second << " ";
			}
			cout << "\n";
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			cin >> map[i][j].first >> map[i][j].second;
		}
	}

	map[0][0].first = 0; // first shark

	show_map(1);
	cout << "======\n";
	show_map(2);

	cout << "\n";
	fish_move();
	
	show_map(1);
	cout << "======\n";
	show_map(2);

	//DFS();

	return 0;
}

