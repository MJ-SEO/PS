#include <iostream>
#include <algorithm>

using namespace std;

int d[100005];
int arr[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	d[0] = 0;
		
	for(int i=1; i<=n; i++){
		cin >> arr[i];
		d[i] = d[i-1] + arr[i];
	}

	for(int i=1; i<=m; i++){
		int t1, t2;
		cin >> t1 >> t2;
		cout << d[t2] - d[t1-1] << "\n";
	}

	return 0;
}
