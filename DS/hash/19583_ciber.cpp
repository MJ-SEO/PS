#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

int timetoint(string time){
	int t = 0;
	string h, m;

	h = time.substr(0,2);
	m = time.substr(3,2);

	t = (60 * stoi(h)) + stoi(m);
	return t;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	string S, E, Q;
	cin >> S >> E >> Q;

	int start_time, end_time, stream_time;
	start_time = timetoint(S);
	end_time = timetoint(E);
	stream_time = timetoint(Q);

	unordered_set<string> start_list;
	unordered_set<string> attend_list;

	while(true){
		string time, name;
		cin >> time >> name;
		if(cin.eof() == true) break;

		if(timetoint(time) <= start_time){
			start_list.insert(name);
		}
		else if(timetoint(time) >= end_time && timetoint(time) <= stream_time){
			if(start_list.find(name) != start_list.end()) {
				attend_list.insert(name);
			}
		}		
	}

	cout << attend_list.size() << "\n";
	return 0;
}