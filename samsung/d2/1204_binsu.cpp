#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int TC;
        cin >> TC;

        int score[101] = {0};
        int binsu = 0;
        int res;

        for(int i=0; i<1000; i++){
            int temp;
            cin >> temp;
            score[temp]++;
        }

        for(int i=0; i<101; i++){
            if(score[i] > binsu){
                binsu = score[i];
                res = i;
            }
        }

        cout << "#" << TC << " " << res << "\n";
	}
	return 0;
}