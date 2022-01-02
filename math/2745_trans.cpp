#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	int b;
	cin >> str >> b;
	int result = 0;

	for(int i=str.size(); i>0; i--){
		int temp = 0;
		if(str[i-1] >= '0' && str[i-1] <= '9'){
			temp = (str[i-1] - '0') * pow(b, str.size() - i);
		}
		else{
			temp = (str[i-1] - 55) * pow(b, str.size() - i);
		}
		result += temp;	
	}


	cout << result << "\n";

	return 0;
}

