#include <iostream>
#include <list>
#include <string>
#include <queue>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    list<int> llist;
    list<int>::iterator cursor;
    queue<int> que;

    for (int i = 0; i < n; i++) {
        que.push(i+1);
    }  

    cout << "<";
    int kk = 1;

    while(!que.empty()){
      int n = 0;
      
      if(kk==k){
        n = que.front();
        cout << n;
        if(que.size() > 1){
          cout<<", ";
        }
        que.pop();
        kk=1;
      }

      n = que.front();
      que.pop();
      que.push(n);
      kk++;
    }

    cout << ">";

    return 0;
}
