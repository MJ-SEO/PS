#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int N, M;
int student[1001][1001];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	int min_val = INT_MAX;

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> student[i][j];
		}
	}


	cout << min_val << "\n"

	return 0;
}

