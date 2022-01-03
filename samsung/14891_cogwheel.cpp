#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <cstring>

using namespace std;

deque<char> wheel1;
deque<char> wheel2;
deque<char> wheel3;
deque<char> wheel4;

int visited[5];

void show_wheels(){
	for(int j=0; j<wheel1.size(); j++){
		cout << wheel1[j] << " ";
	}	
	cout << "\n";
	for(int j=0; j<wheel2.size(); j++){
		cout << wheel2[j] << " ";
	}	
	cout << "\n";
	for(int j=0; j<wheel3.size(); j++){
		cout << wheel3[j] << " ";
	}	
	cout << "\n";
	for(int j=0; j<wheel4.size(); j++){
		cout << wheel4[j] << " ";
	}	
	cout << "\n";
}

void rotate(int wheel, int direction){
	if(wheel == 1){
		visited[wheel] = 1;
		if(direction == 1){
			char temp = wheel1.back();
			wheel1.pop_back();
			wheel1.push_front(temp);
			if(wheel1[3] != wheel2[6] && visited[2] == 0) rotate(2, -1);
		}
		else{
			char temp = wheel1.front();
			wheel1.pop_front();
			wheel1.push_back(temp);
			if(wheel1[1] != wheel2[6] && visited[2] == 0) rotate(2, 1);
		}
	}
	else if(wheel == 2){
		visited[wheel] = 1;
		if(direction == 1){
			char temp = wheel2.back();
			wheel2.pop_back();
			wheel2.push_front(temp);
			if(wheel2[7] != wheel1[2] && visited[1] == 0) rotate(1, -1);
			if(wheel2[3] != wheel3[6] && visited[3] == 0) rotate(3, -1);
		}
		else{
			char temp = wheel2.front();
			wheel2.pop_front();
			wheel2.push_back(temp);
			if(wheel2[5] != wheel1[2] && visited[1] == 0) rotate(1, 1);
			if(wheel2[1] != wheel3[6] && visited[3] == 0) rotate(3, 1);
		}
	}
	else if(wheel == 3){
		visited[wheel] = 1;
		if(direction == 1){
			char temp = wheel3.back();
			wheel3.pop_back();
			wheel3.push_front(temp);
			if(wheel3[7] != wheel2[2] && visited[2] == 0) rotate(2, -1);
			if(wheel3[3] != wheel4[6] && visited[4] == 0) rotate(4, -1);
		}
		else{
			char temp = wheel3.front();
			wheel3.pop_front();
			wheel3.push_back(temp);
			if(wheel3[5] != wheel2[2] && visited[2] == 0) rotate(2, 1);
			if(wheel3[1] != wheel4[6] && visited[4] == 0) rotate(4, 1);
		}
	}
	else{
		visited[wheel] = 1;
		if(direction == 1){
			char temp = wheel4.back();
			wheel4.pop_back();
			wheel4.push_front(temp);
			if(wheel4[7] != wheel3[2] && visited[3] == 0) rotate(4, -1);
		}
		else{
			char temp = wheel4.front();
			wheel4.pop_front();
			wheel4.push_back(temp);
			if(wheel4[5] != wheel3[2] && visited[3] == 0) rotate(4, 1);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	for(int i=0; i<4; i++){
		string temp;
		cin >> temp;
		for(int j=0; j<8; j++){
			if(i==0) wheel1.push_back(temp[j]);
			else if(i==1) wheel2.push_back(temp[j]);
			else if(i==2) wheel3.push_back(temp[j]);
			else wheel4.push_back(temp[j]);
		}
	}

	int k;
	cin >> k;

	for(int i=0; i<k; i++){
		int w_num, direction;
		cin >> w_num >> direction;

		rotate(w_num, direction);

		for(int j=1; j<=4; j++){
			visited[j] = 0;
		}
	}

	int score = 0;
	
	if(wheel1[0] == '1') score += 1;
	if(wheel2[0] == '1') score += 2;
	if(wheel3[0] == '1') score += 4;
	if(wheel4[0] == '1') score += 8;

	cout << score << "\n";

	return 0;
}

