#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;
using tp = tuple<int,int,int>;

int N, M;
int parent[100005];
vector<tuple<int, int, int>> edge;
int ANS;

int find(int x){
	if(x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void uni(int a, int b){
	a = find(a);
	b = find(b);

	if(a < b) 
		parent[b] = a;
	else
		parent[a] = b;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for(int i=0; i<N; i++){
		parent[i] = i;
	}
	

	for(int i=0; i<M; i++){
		int a, b, cost;
		cin >> a >> b >> cost;

		edge.push_back({cost, a, b});
	}

	sort(edge.begin(), edge.end());
	int count = 0;

	for(int i=0; i<M; i++){
		int a, b, cost;
		tie(cost, a, b) = edge[i];

		cout << "DEBUG " << a << " " << b << " " << cost << "  ";

		if(find(a) == find(b)) continue;

		ANS += cost;
		count++;
		
		cout << count << " !\n";

		if(count == N-2) break;
		
		uni(a, b);
	}

	cout << ANS << "\n";

	return 0;
}

