#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <string>
#include <stack>

using namespace std;

int main(){
	int n;
	string buf;
	cin >> n;
	getline(cin, buf);

	stack<int> st;

	for(int i=0; i<n; i++){
		string op;
		getline(cin, op);
		if(op.find("push") != string::npos){
			int num = stoi(op);
				
		/*
			op.replace(0,4,"");
			int num = atoi(op.c_str());			
			st.push(num);

			for(int i=0; i<op.length(); i++){
				if(atoi(op.c_str()) !=0){
					num = atoi(op.c_str());
					break;
				}
			}
*/
//			cout << "str:" << op << "\n";
//			cout << "num:" << num << endl;
		}
		if(op=="pop"){
			if(st.empty()){
				cout << "-1" << endl;
			}
			else{
				int num = st.top();
				cout << num << endl;
				st.pop();
			}
		}
		if(op=="size"){
			int num;
		       	num = st.size();
			cout << num << endl;
		}
		if(op=="empty"){
			if(st.empty()){
				cout << "1" << endl;
			}
			else{
				cout << "0" << endl;
			}
		}
		if(op=="top"){
			if(st.empty()){
				cout << "-1" << endl;
			}
			else{
				int num = st.top();
				cout << num << endl;
			}
		}
//		getline(cin, buf);
	}

	return 0;
}
