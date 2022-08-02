#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
	stack<char> st;
	int result = 0;
	int temp = 1;
	string str;
	getline(cin, str);
	
	for(int i=0; i<str.length(); i++){
		if (str[i] == '('){
			temp *= 2;
			st.push(str[i]);	
		}
		else if (str[i] == '['){
			temp *= 3;
			st.push(str[i]);	
		}
		else if (str[i] == ')'){
				if (st.empty() || st.top() != '('){
					result = 0;
					break;
				}
				else if (str[i-1] == '('){
					result += temp;
					temp /= 2;
					st.pop();
				}
				else{
					temp /=2;
					st.pop();
				}
		}
		else if (str[i] == ']'){
				if (st.empty() || st.top() != '['){
					result = 0
					break;
				}
				else if (str[i-1] == '['){
					result += temp;
					temp /= 3;
					st.pop();
				}
				else{
					temp /=3;
					st.pop();
				}
		}
	}

	if (st.size() != 0){
		cout << "0" << "\n"; 
	}
	else{
		cout << result << "\n";
	}
	return 0;
}
