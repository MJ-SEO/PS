#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

vector <pair<int, int>> tree[26];

void preorder(int node){
	cout << (char)(node + 'A');
	for(int i=0; i<tree[node].size(); i++)
		preorder(tree[node][i].first);
}

void inorder(int node){
	if (tree[node].size() && tree[node][0].second)
		inorder(tree[node][0].first);

	cout << (char)(node + 'A');

	if (tree[node].size() && !tree[node][0].second)
		inorder(tree[node][0].first);
	else if (tree[node].size() == 2)
		inorder(tree[node][1].first);
}

void postorder(int node){
	for(int i=0; i<tree[node].size(); i++)
		postorder(tree[node][i].first);
	cout << (char)(node + 'A');
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for(int i=0; i<n; i++){
		char root, left, right;
		cin >> root >> left >> right;

		if(left != '.')
			tree[root - 'A'].push_back({left - 'A', 1});	

		if(right != '.')
			tree[root - 'A'].push_back({right - 'A', 0});	
	}

	preorder(0);
	cout << "\n";
	inorder(0);
	cout << "\n";
	postorder(0);
	cout << "\n";

	return 0;
}
