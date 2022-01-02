#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
	stack<char> st;

	while(1){
		string str;
		cin >> str;
	//	cout << "DEBUG str: " << str << "\n";

		for(auto e : str){
			if(e == '.') continue;
	//		cout << "DEBUG e: " << e << "\n";
			if(e == '('){
	//			cout << "d( \n"; 
				st.push(e);			
			}
			if(e == '['){
	//			cout << "d[ \n"; 
				st.push(e);
			}
			if(e == ']'){
				if(st.top() == '['){
					st.pop();
				}
				else{
					cout << "no" << "\n";
					continue;
				}
			}
			if(e == ')'){
				if(st.top() == '('){
					st.pop();
				}
				else{
					cout << "no" << "\n";
					continue;
				}
	
			}
		}

		if(st.size() == 0){
			cout << "yes\n";
		}
	}

	return 0;
}
