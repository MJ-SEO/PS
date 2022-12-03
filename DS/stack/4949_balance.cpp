#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
	while(1){
		int flag = 0;
		string str;
		stack<char> st;
		getline(cin, str);

		if(str == ".") break;

		for(auto e : str){
			if(e == '.') break;

			if(e == '(' || e == '['){
				st.push(e);			
			}

			if(e == ']'){
				if(st.empty() || st.top() != '[') {
					flag = 1;
					break;
				}
				else{
					st.pop();
				}
			}
			if(e == ')'){
				if(st.empty() || st.top() != '(') {
					flag = 1;
					break;
				}
				else{
					st.pop();
				}
			}
		}

        if((flag == 0)&&(st.empty()))
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
	}

	return 0;
}
