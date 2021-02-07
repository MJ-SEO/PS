#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <string>
#include <deque>

using namespace std;

int main(){
        int n;
        string buf;
        cin >> n;
        getline(cin, buf);

        deque<int> deck;

        for(int i=0; i<n; i++){
                string op;
                getline(cin, op);
                if(op.find("push_back") != string::npos){
                        op.replace(0,9,"");
                        int num = atoi(op.c_str());
                        deck.push_back(num);
                }
                if(op.find("push_front") != string::npos){
                        op.replace(0,10,"");
                        int num = atoi(op.c_str());
                        deck.push_front(num);
                }
                if(op=="pop_front"){
                        if(deck.empty()){
                                cout << "-1" << endl;
                        }
                        else{
                                int num = deck.front();
                                cout << num << endl;
                                deck.pop_front();
                        }
                }

	
                        if(deck.empty()){
                                cout << "-1" << endl;
                        }
                        else{
                                int num = deck.back();
                                cout << num << endl;
                                deck.pop_back();
                        }
                }
                if(op=="size"){
                        int num;
                        num = deck.size();
                        cout << num << endl;
                }
                if(op=="empty"){
                        if(deck.empty()){
                                cout << "1" << endl;
                        }
                        else{
                                cout << "0" << endl;
                        }
                }
                if(op=="front"){
                        if(deck.empty()){
                                cout << "-1" << endl;
                        }
                        else{
                                int num = deck.front();
                                cout << num << endl;
                        }
                }
                if(op=="back"){
                        if(deck.empty()){                                        
                                cout << "-1" << endl;     
                        }
                        else{
                                int num = deck.back();
                                cout << num << endl;
                        } 
                }
	}
        return 0;
}
