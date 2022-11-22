#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <set>

using namespace std;

int N;

unordered_set<string> office;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for(int i=0; i<N; i++){
		string name, eorl;
		cin >> name >> eorl;

		if(eorl == "enter"){
			office.insert(name);
		}
		else{
			office.erase(name);
		}
	}

	vector<string> result(office.begin(), office.end());
	sort(result.begin(), result.end(), greater<string>());

	for(auto e:result){
		cout << e << "\n";
	}

	return 0;
}

