#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int map[101][101];
int visited[101][101];
int result[101];
int n, relation;

void dfs(int row){
	for(int i=1; i<=n; i++){
		if(map[row][i] == 1 && result[i] == 0){
			result[i] = 1;
			dfs(i);	
		}
	}
}

int main(){
	cin.tie(0);
	int answer = 0;
	cin >> n >> relation;
	
	for(int i=0; i<relation; i++){
		int t1, t2;
		cin >> t1 >> t2;
		
		map[t1][t2] = 1;
	//	map[t2][t1] = 1;
	}

	cout << "DEBUG n: " << n << "\n";

	for(int i=0; i<=n; i++){
		for(int j=0; j<=n; j++){
			cout << map[i][j] << " ";
		}
		cout <<"\n";
	}

	dfs(1);

	for(int i=0; i<101; i++){
		if(result[i] == 1) answer++;
	}

	cout << answer << "\n";
	return 0;
}
