#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
    string str;
    getline(cin, str);
    int n;
    cin >> n;

    list<char> llist;
    list<char>::iterator cursor;

    for (int i = 0; i < str.length(); i++) {
        llist.push_back(str[i]);
    }  

    cursor = llist.end();

    for(int i=0; i<n; i++){
        char op;
        cin >> op;
        if(op == 'L'){
            if(cursor != llist.begin()){
              cursor--;
            }
        }
        else if(op == 'D'){
            if(cursor != llist.end()){
              cursor++;
            }
        }
        else if(op == 'B'){
            if(cursor != llist.begin()){
              cursor--;
              cursor = llist.erase(cursor);
            }
        }
        else if(op == 'P'){
            char t;
            cin >> t;
            llist.insert(cursor, t);
        }
        else{
        }
    }

    int nn = llist.size();

    for(int i=0; i<nn; i++){
      char temp;
      temp = llist.front(); llist.pop_front();
      cout << temp;
    }

    return 0;
}
