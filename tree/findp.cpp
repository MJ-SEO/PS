#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef struct{
    int vertex;
    int* edge;
} node_t;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> g[n];

    for(int i=1; i<n; i++){
        int start, end;
        cin >> start >> end;
        g[start].push_back(end);
        g[end].push_back(start);
    }

    for(int i=1; i<n; i++){
   	 for(auto e : g[i]){
   	     cout << e << " ";
   	 }
   	 cout << "\n";
    }

     cout << "========================\n\n";

     for(int i=1; i<n; i++){
	int num = g[i].size();
	cout << "DEBUG size: " << num << "\n";
     }

    return 0;
}
