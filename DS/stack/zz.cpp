#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int main(){
	int n;
	cin >> n;
	cin.ignore();
	
	for(int i=0; i<n; i++){
		stack<char> st;
		string buf;
		getline(cin, buf);
		int flag = 0;

		for(int j=0; j<buf.size(); j++){
			if(buf[j] == '('){
				st.push(buf[j]);
			}
			else{
				if(!st.empty()){
					st.pop();
				}
				else{
					flag = 1;
				}
			}
		}
		
		if(st.size() == 0 && flag == 0){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}
