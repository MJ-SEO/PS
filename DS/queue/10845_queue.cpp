#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <string>
#include <queue>

using namespace std;

int main(){
        int n;
        string buf;
        cin >> n;
        getline(cin, buf);

        queue<int> que;

        for(int i=0; i<n; i++){
                string op;
                getline(cin, op);
                if(op.find("push") != string::npos){
                        op.replace(0,4,"");
                        int num = atoi(op.c_str());
                        que.push(num);
                }
                if(op=="pop"){
                        if(que.empty()){
                                cout << "-1" << endl;
                        }
                        else{
                                int num = que.front();
                                cout << num << endl;
                                que.pop();
                        }
                }
                if(op=="size"){
                        int num;
                        num = que.size();
                        cout << num << endl;
                }
                if(op=="empty"){
                        if(que.empty()){
                                cout << "1" << endl;
                        }
                        else{
                                cout << "0" << endl;
                        }
                }
                if(op=="front"){
                        if(que.empty()){
                                cout << "-1" << endl;
                        }
                        else{
                                int num = que.front();
                                cout << num << endl;
                        }
                }
                if(op=="back"){
                        if(que.empty()){                                        
                                cout << "-1" << endl;     
                        }
                        else{
                                int num = que.back();
                                cout << num << endl;
                        } 
                }
	}
        return 0;
}
