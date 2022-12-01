#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;

int g_grade[7];
int m_grade[7];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	int res = 0;

	for(int i=0; i<N; i++){
		int S, Y;
		cin >> S >> Y;
		if(S == 0){
			g_grade[Y]++;
		}
		else{
			m_grade[Y]++;
		}
	}

	for(int i=1; i<=6; i++){
		while(g_grade[i] > 0){
			res++;
			g_grade[i] = g_grade[i]-K;
		}
		while(m_grade[i] > 0){
			res++;
			m_grade[i] = m_grade[i]-K;
		}	
	}

	cout << res << "\n";

	return 0;
}

