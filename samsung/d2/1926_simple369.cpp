#include<iostream>

using namespace std;

int check(int n){
	int cnt = 0;

	while(n){
		if(n%10 == 3 || n%10 == 6 || n%10 == 9) cnt++;
		n = n/10;
	}

	return cnt;
}

void solve(int n){
	for(int i=1; i<=n; i++){
		int cnt = 0;
		cnt = check(i);
		
		if(cnt){
			for(int j=0; j<cnt; j++){
				cout << "-";
			}
			cout << " ";
		}
		else{
			cout << i << " ";
		}
	}
}

int main(int argc, char** argv)
{
	int N;
	cin >> N;

	solve(N);

	return 0;
}