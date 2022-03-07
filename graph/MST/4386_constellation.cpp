#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cmath>

using namespace std;

int N;
int p[105];

vector<pair<double, int>> graph[105];
vector<tuple<double, int, int>> edge;
double storage[101][101];

double get_weight(int a, int b){
	double dist;
	dist = sqrt(pow((storage[a][0] - storage[b][0]),2) + pow((storage[a][1] - storage[b][1]),2));
	return dist;
}

void modeling_graph(){
	for(int i=0; i<N-1; i++){
		for(int j=i+1; j<N; j++){
	//		graph[i].push_back({get_weight(i, j), j});
	//		graph[j].push_back({get_weight(i, j), i});
			edge.push_back({get_weight(i, j), i, j});
		}
	}
}

int find(int x){
	if(x == p[x]) return x;
	return p[x] = find(p[x]);
}

void unions(int a, int b){
	a = find(a);
	b = find(b);
	
	if(a < b) p[b] = a;
	else p[a] = b;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for(int i=0; i<N; i++){
		p[i] = i;
		cin >> storage[i][0] >> storage[i][1];
	}

	modeling_graph();

/*
	for(int i=0; i < edge.size(); i++){
		cout << "[" << i << "] ";
		int a, b;
		double zz;
		tie(zz, a, b) = edge[i];
		cout << a << " " << b << " " << zz << "\n";
	}
*/
	sort(edge.begin(), edge.end());
	
	int count = 0;
	double ans = 0;

	for(int i=0; i<edge.size(); i++){
		int a, b;
		double distance;
		tie(distance, a, b) = edge[i];
	
		if(find(a) == find(b)) continue;
		
		ans += distance;
		count++;
		unions(a, b);
	}

	cout << fixed;
	cout.precision(2);

	cout << ans << "\n";

	return 0;
}

