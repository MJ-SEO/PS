#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> city[12];
int population[12];
int visited[12];
int res;

void solve(){

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	
	for(int i=1; i<=N; i++){
		cin >> population[i];
	}

	for(int i=1; i<=N; i++){
		int num;
		cin >> num;

		for(int j=0; j<num; j++){
			int adj;
			cin >> adj;
			vector[i].push_back(adj);
		}
	}

	solve();

	cout << res << "\n";

	return 0;
}

