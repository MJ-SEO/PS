#include <iostream>

using namespace std;

int n, r, c;
int x, y, result;

void func(int x, int y, int n){

        if(x == r && y == c){
                cout << result << "\n";
                return;
        }

        if(r < n + x && r >= x && c < y+n && c >= y){
                func(x, y, n/2);
                func(x, y+n/2, n/2);
                func(x+n/2, y, n/2);
                func(x+n/2, y+n/2, n/2);
        }
        else{
                result += n*n;
                cout << result << "\n";
        }
}


int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin >> n >> r >> c;

        func(0, 0, (1 << n));

        return 0;
}