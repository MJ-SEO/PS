#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int main(){
	int i = 1;
	while(1){
		stack<char> st;
		int change = 0;
		string buf;
		getline(cin, buf);
		if(buf[0] == '-') break;
		
		for(int i=0; i<buf.size(); i++){
			if(buf[i] == '{'){
				st.push(buf[i]);
			}
			else{
				if(st.size() == 0){
					change+=1;
					st.push('{');
				}
				else{
					st.pop();
				}
			}
		}
		change += st.size()/2;

		printf("%d. %d\n", i, change);
		i++;
	}
	return 0;
}
