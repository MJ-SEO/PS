#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define X first
#define Y second

int map[25][25];
int visited[25][25];
int dist[25][25][2];

int result;
int shark;
int eat;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int os_x;
int os_y;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	shark = 2;

	queue<pair<int, int>> que;


	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> map[i][j];
			if(map[i][j] == 9){
				que.push({i,j});		
				visited[i][j] = 1;		
				os_x = i;
				os_y = j;
			}
		}
	}

while(1){
	int check = 0;
	while(!que.empty()){
		pair<int,int> cur;
		cur = que.front(); que.pop();

		for(int i=0; i<4; i++){
			int x = cur.X + dx[i];
			int y = cur.Y + dy[i];

			if(x<0 || x>=n || y<0 || y>=n) continue;
	
			if(visited[x][y] || map[x][y] > shark) continue;
			if(map[x][y] < shark && map[x][y] > 0){
				dist[x][y][1] = 1;
				check++;
				//	if(eat == shark) shark++; eat = 0;
			}

			que.push({x,y});
			visited[x][y] = 1;
			dist[x][y][0] = dist[cur.X][cur.Y][0] + 1;
		}		
	}
	
	if(check == 0) break;

	int tmax = 1000;
	int ns_x;
	int ns_y;

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(dist[i][j][1] == 1 && dist[i][j][0] < tmax){
				tmax = dist[i][j][0];
				ns_x = i;
				ns_y = j;	
	//			cout << "[DEBUG] " << ns_x << " " << ns_y << " " << tmax << "\n";
			}
		}
	}
	
	eat++;
	result += tmax;



	cout << "[DEBUG] EAT >>  (" << ns_x << ", " << ns_y << ") " << tmax << "\n";
	cout << "[DEBUG] eat, shark >>  " << eat << " " << shark <<  "\n";

		
	if(eat == shark){
		shark++;
		eat = 0;
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			visited[i][j] = 0;
			dist[i][j][0] = 0;
			dist[i][j][1] = 0;
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << map[i][j] << " ";	
		}
		cout << "\n";
	}
	

	map[os_x][os_y] = 0;
	map[ns_x][ns_y] = 9;
	
	que.push({ns_x,ns_y});				
	visited[ns_x][ns_y] = 1;
	os_x = ns_x;
	os_y = ns_y;	
}

	cout << result << "\n";
	return 0;
}
