#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
	stack<char> st;
	int result = 0;
	string str;
	getline(cin, str);
	
	for(int i=0; i<str.size(); i++){
		if(str[i] == '(' || str[i] == '['){
			st.push(str[i]);			
		}
		else {
			st.pop();
			if(str[i-1] == ')'){
			
			}
			if(str[i-1] == ']'){
			
			}	
			else{
				result+=1;
			}
		}
	}

	cout << result << "\n";
	return 0;
}
