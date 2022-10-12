#include <iostream>
#include <algorithm>

using namespace std;

int K;
int lotto[50];
int result[50];
int isused[50];

void func(int k, int t){
        if(k == 6){
                for(int i=0; i<6; i++){
                        cout << result[i] << " ";
                }
                cout << "\n";
                return;
        }

        for(int i=t; i<K; i++){
                result[k] = lotto[i];
                func(k+1, i+1);
        }
}


int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);

	while(1){
                cin >> K;
                if(K == 0) break;

                for(int i=0; i<K; i++){
                        cin >> lotto[i];
                }

                func(0, 0);    
                cout << "\n";
	}

        return 0;
}

