#include <iostream>
#include <list>
#include <string>
#pragma warning(disable:4996)

using namespace std;

int main() {
    int n;
    cin >> n;

    while(n--){
        string str;
    	cin >> str;

        list<char> llist;
        list<char>::iterator cursor;

        cursor = llist.begin();

	int size = str.size();
	int idx = 0;

	while(idx < size){
		if(str[idx] == '<'){
                    if(cursor != llist.begin()){
                     cursor--;
                   }
                }
                else if(str[idx] == '>'){
                    if(cursor != llist.end()){
                      cursor++;
                    }
                }
                else if(str[idx] == '-'){
                    if(cursor != llist.begin()){
			llist.erase((--cursor)++);
		    }
		}
                else{
                  llist.insert(cursor, str[idx]);
                }
		 
		idx++;
	}

	for(auto x : llist){
		printf("%c", x);
	}
	printf("\n");
      }       
}
