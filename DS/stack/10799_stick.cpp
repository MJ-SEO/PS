#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
	stack<char> st;
	int num = 0;
	int result = 0;
	string str;
	getline(cin, str);
	
	for(int i=0; i<str.size(); i++){
		if(str[i] == '('){
			st.push(str[i]);			
			num++;
		}
		else {
			st.pop(); num--;
			if(str[i-1] == '('){
				result+=num;	
			}
			else{
				result+=1;
			}
		}
	}

	cout << result << "\n";
	return 0;
}
