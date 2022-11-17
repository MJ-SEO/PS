#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int map[11][11];
int visited[11][11];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};  // 우 >> 하 >> 좌 >> 상

queue<pair<int, int>> que;

void BFS(int N){
    int s_num = 1;
    map[0][0] = s_num;
    visited[0][0] = 1;

    int dir = 0; 

    while(!que.empty()){
        if(s_num >= N*N) break;

        pair<int, int> cur = que.front(); que.pop();
        
        int nx = cur.first + dx[dir];
        int ny = cur.second + dy[dir];

        if(nx < 0 || nx >=N || ny < 0 || ny >= N || visited[nx][ny]){
            dir++;
            dir %= 4;
            nx = cur.first + dx[dir];
            ny = cur.second + dy[dir];
        } 

        s_num++;
        map[nx][ny] = s_num;
   
        que.push({nx, ny});
        visited[nx][ny] = 1;
    }
}

void snail(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}

void reset(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            map[i][j] = 0;
            visited[i][j] = 0;
        }
    }
    while(!que.empty()){
        que.pop();
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N;
        cin >> N;

        que.push({0, 0});

        BFS(N);

        cout << "#" << test_case << "\n";
        snail(N);   

        reset(N);
    }
	return 0;
}