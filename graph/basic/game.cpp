#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define X first
#define Y second

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<int,int>> g;
	vector<int> save;

	for(int i=0; i<n; i++){
		while(1){
			int t;
			cin >> t;
			save.push_back(t);
			if(t == -1) break;
		/*	pair<int,int> temp;
			temp.X = t;
			temp.Y = i;
			g.push_back(temp);		*/
		}
	}

	for(int i=0; i<save.size(); i++){
		cout << "DEBUG save[i]: " << save[i] << "\n";
	}
	return 0;
}
