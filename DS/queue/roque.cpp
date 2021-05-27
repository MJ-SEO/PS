#include <iostream>
#include <deque>
#include <vector>
#include <cstring>

using namespace std;

int main(){
	int capacity;
	int find;
	int min = 0;
	string buf;
	cin >> capacity >> find;

	deque<int> deck;
	vector<int> list;
	list.assign(find, 0);

	cout << "capa, find: " << capacity << " "  <<  find << endl;

	for(int i=0; i<capacity; i++){
		deck.push_back(i+1);
	}

	for(int i=0; i<find; i++){
		int k;
		cin >> k;
		list[i] = k;
	}

	for(int i=0; i<find; i++){
		int idx = 0;
		for(int j=0; j<deck.size(); j++){
			if(deck[j] == list[i]){
				idx = j;
				break;				
			}
		}

		if(idx < deck.size() - idx){
			while(1){
				if(deck.front() == list[i]){
					deck.pop_front();
					break;
				}
				min++;
				deck.push_back(deck.front());
				deck.pop_front();
			}
		}
		else{
			while(1){
				if(deck.front() == list[i]){
					deck.pop_front();
					break;
				}
				min++;
				deck.push_front(deck.back());
				deck.pop_back();
			}
		}
	}
	
	cout << "min:" << min << endl;
}
