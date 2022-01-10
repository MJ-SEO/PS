#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
queue<tuple<int, int, int>> que;
int N, M;

int map[10][10];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cout << "DEBUG " << i << " " << j << "\n";
			cin >> map[i][j];
			if(i==2 && j==2){
				que.push(make_tuple(1, 2, 3));
			}
		}
	}


	tuple<int ,int, int> temp = que.front();

	cout << get<0>(temp) << " " << get<1>(temp) << " " << get<2>(temp) << "\n";

	return 0;
}
