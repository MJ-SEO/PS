#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int sh[105];

void flip(int idx){
	if(sh[idx] == 1) sh[idx] = 0;
	else if(sh[idx] == 0) sh[idx] = 1;
}

int find_sym(int num){
	int temp = 1;
	int left = num;
	int rigth = num;

	while(1){
		left -= 1;
		rigth += 1;

		if(left < 1 || rigth > N) break;
		if(sh[left] != sh[rigth]) break;

		temp++;
	}

	return temp;
}

void flip_sh(int mid, int section){
	flip(mid);
	if(section > 1){
		for(int i=1; i<section; i++){
			flip(mid+i);
			flip(mid-i);
		}
	}
}

void op(int gender, int num){
	if(gender == 1){
		for(int i=num; i<=N; i += num){
			flip(i);
		}
	}
	else{
		int section = 0;
		section = find_sym(num);
		flip_sh(num, section);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for(int i=1; i<=N; i++){
		cin >> sh[i];
	}

	int student;
	cin >> student;

	for(int i=0; i<student; i++){
		int gender, num;
		cin >> gender >> num;
		
		op(gender, num);
	}

	for(int i=1; i<=N; i++){
		cout << sh[i] << " ";
		if(i%20 == 0) cout << "\n";
	}
	cout << "\n";
	return 0;
}

