#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
	
	string str;
	getline(cin, str);

	for(int i=0; i<str.size(); i++){
		if((str[i] >= 'a' && str[i] <= 'm') || (str[i] >= 'A' && str[i] <= 'M')){
			str[i] = str[i]+13;
		}
		else if(str[i] >= 'n' && str[i] <= 'z'){
			str[i] = str[i]-13;
		}
		else if(str[i] >= 'N' && str[i] <= 'Z'){
			str[i] = str[i]-13;
		}
		else if(str[i] == ' '){
			str[i] = ' ';
		}
	}

	cout << str << "\n";
	
        return 0;
}

