#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <string>
#include <stack>

using namespace std;

int main(){
	stack<char> st;
	int i = 1;
	while(1){
		int min = 0;
		string buf;
		getline(cin, buf);
		if(buf[0] == '-') break;
		
		for(int i=0; i<buf.length(); i++){
	//		cout << buf[i] << endl;
			st.push(buf[i]);
		}

		
		
		printf("%d. %d\n", i, min);
		i++;
	}
	return 0;
}
