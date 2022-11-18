#include<iostream>

using namespace std;

int nqueen[11];
int cnt;

bool check(int col){

	for(int i=0; i<col; i++){
		if(nqueen[i] == nqueen[col] || abs(nqueen[col] - nqueen[i]) == col - i) return false;
	}

	return true;
}

void track(int cur, int N){
	if(cur == N){
		cnt++;
		return;
	} 

	for(int i=0; i<N; i++){
		nqueen[cur] = i;
		if(check(cur)){
			track(cur+1, N);
		}
	}	
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{	
		int n;
		cin >> n;
		cnt = 0;

		track(0, n);

		cout << "#" << test_case << " " << cnt << "\n";	
	}
	return 0;
}