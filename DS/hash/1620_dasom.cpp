#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int N, M;
string arr[100001];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	unordered_map<string, int> dictionary;

	for(int i=1; i<=N; i++){
		string name;
		cin >> name;

		dictionary[name] = i;
		arr[i] = name;
	}

	for(int i=0; i<M; i++){
		string temp;
		cin >> temp;

		if(isdigit(temp[0])){
			cout << arr[stoi(temp)] <<"\n";
		}
		else{
			cout << dictionary[temp] << "\n";
		}
	}

	return 0;
}

