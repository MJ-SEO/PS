#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>

using namespace std;

deque<int> deck;

void strtoint(string str, deque<int>& deck){
	int cur = 0;
  	for(int i = 1; i+1 < str.size(); i++){
    	if(str[i] == ','){
      		deck.push_back(cur);
      		cur = 0;
    	}	
    	else{
      		cur = 10 * cur + (str[i] - '0');
    	}
  	}

  	if(cur != 0)
   	 	deck.push_back(cur);

/*	
	str.erase(0,1);
	str.erase(str.size()-1, 1);

	if(n == 1) deck.push_back(stoi(str));
	else{
		for(int i=0; i<n; i++){
			deck.push_back(stoi(str.substr(0, str.find(","))));
			str.erase(0, str.find(",") + 1);
		}
	}
*/
}

void print_result(int rev, deque<int>& deck){
	int dsize = deck.size();
	cout << '[';

	if(rev == 0){	
		for(int i=dsize-1; i>=0; i--){	
			cout << deck[i];
			if(i > 0) cout << ",";
		}
	}
	else{
		for(int i=0; i<dsize; i++){
			cout << deck[i];
			if(i != dsize-1) cout << ",";
		}
	}

	cout << "]\n";
}

void solve(string op, deque<int>& deck){
	int dsize = deck.size();
	int rev = 1;
	int flag = 0;

	for(auto e : op){
		if(e == 'R'){
			rev = 1 - rev;
		}
		else{
			if(deck.empty()) {
				flag = 1;
				break;
			}
			
			if(rev == 0){
				deck.pop_back();
			}
			else{
				deck.pop_front();
			}
		}
	}

	if(flag) {
		cout << "error\n";
		return;
	}

	print_result(rev, deck);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for(int i=0; i<T; i++){
		deque<int> deck;

		string p;
		cin >> p;

		int n;
		cin >> n;

		string array;
		cin >> array;

		strtoint(array, deck);
		solve(p, deck);
	}

	return 0;
}