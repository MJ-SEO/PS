#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(){
        ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	while(getline(cin, str)){
		int store[4] = {0};
		for(int i=0; i<str.size(); i++){
			if(str[i] >= 'a' && str[i] <= 'z'){
				store[0]++;
			}
			else if(str[i] >= 'A' && str[i] <= 'Z'){
				store[1]++;
			}
			else if(str[i] >= '0' && str[i] <= '9'){
				store[2]++;
			}
			else if(str[i] == ' '){
				store[3]++;
			}	
		}
		cout << store[0] << " " << store[1] << " " << store[2] << " " << store[3] << "\n";
	}
	return 0;
}

