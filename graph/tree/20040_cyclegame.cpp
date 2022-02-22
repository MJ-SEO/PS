#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int parent[500001];
int N, M;

int find(int a) {
	if (a == parent[a]) return a;
	return parent[a] = find(parent[a]);
}

void do_union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}

	for (int turn = 1; turn <= M; turn++) {
		int a, b;
		cin >> a >> b;

		if (find(a) == find(b)) {
			cout << turn << "\n";
			return 0;
		}
		do_union(a, b);
	}

	cout << 0 << "\n";
	return 0;
}
