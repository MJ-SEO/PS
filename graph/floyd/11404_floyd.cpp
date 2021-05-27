#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

const int INF = 1e9+10;

int map[105][105];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		fill(map[i], map[i]+1+n, INF);

	while(m--){
		int a,b,c;
		cin >> a >> b >> c;
		map[a][b] = min(map[a][b], c);
	}

	for(int i = 1; i <= n; i++) map[i][i] = 0;

	cout << "============INIT============\n";
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(map[i][j] == INF) cout << "0 ";
			else cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "============================\n";



	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				map[i][j] = min(map[i][j], map[i][k]+map[k][j]);

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(map[i][j] == INF) cout << "0 ";
			else cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}

