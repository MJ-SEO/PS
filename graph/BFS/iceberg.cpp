#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
int map[305][305];
int bef_map[305][305];
int visited[305][305];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

#define X first
#define Y second

int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
	cin >> n >> m;
	int result = 0;
	int sol;
	queue<pair<int,int>> que;

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> map[i][j];
		}
	}
	
	while(1){
	int flag = 0;
	int end = 1;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(map[i][j] != 0) end = 0;
		}
	}
	
	if(end == 1) break;
	memcpy(bef_map, map, sizeof(map));
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(visited[i][j] || bef_map[i][j] == 0) continue;
				flag++;
				if(flag == 2) sol = result;
		//		cout << "[DEBUF] flag: " << flag << "\n";
				pair<int, int> ice;
				ice.X = i;
				ice.Y = j;
				que.push(ice);
				visited[i][j] = 1;
				
				while(!que.empty()){
					pair<int, int> cur = que.front(); que.pop();
					int melt = 0;
					for(int i=0; i<4; i++){
						int x = cur.X + dx[i];
						int y = cur.Y + dy[i];
					//	cout << "DEBUG x, y: " << x << " " << y << "\n";
							
						if(x < 0 || x >= n || y < 0 || y >= m) continue;
						if(bef_map[x][y] == 0){
						       	melt++; 
							continue;
						}
						if(visited[x][y]) continue;
						
						que.push({x, y});
					//	cout << "DEBUG push: " << x << " " << y << "\n";
						visited[x][y] = 1;
	
					}
		//			cout << "[DEBUG] x, y, melt " << cur.X << " " << cur.Y << " " << melt << "\n";
					map[cur.X][cur.Y] = bef_map[cur.X][cur.Y] - melt;
					if(map[cur.X][cur.Y] < 0) map[cur.X][cur.Y] = 0;	
				}	
		}
	}
	
	result++;			
		
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			visited[i][j] = 0;
		}
	}
	
	memcpy(bef_map, map, sizeof(map));
	
	}
	
	cout << sol << "\n";

        return 0;
}
