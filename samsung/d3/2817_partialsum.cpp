#include<iostream>

using namespace std;

int arr[21];
int N, K;
int cnt;

void track(int cur, int sum){
	if(cur == N){
		if(sum == K){
			cnt++;
		}
		return;
	}

	track(cur+1, sum);
	track(cur+1, sum + arr[cur]);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> K;
		cnt = 0;

		for(int i=0; i<N; i++){
			cin >> arr[i];
		}

		track(0, 0);

		cout << "#" << test_case << " " << cnt << "\n";	
	}
	return 0;
}