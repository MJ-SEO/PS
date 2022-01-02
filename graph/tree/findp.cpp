#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

vector<int> graph[100005];
int result[100005];
int visited[100005];
queue<int> que;

void BFS(){
	while(!que.empty()){
		int curr = que.front(); que.pop();
		for(int i=0; i<graph[curr].size(); i++){
			if(visited[graph[curr][i]] == 1) continue;
			visited[graph[curr][i]] = 1;
			result[graph[curr][i]] = curr;
			que.push(graph[curr][i]);
		}
	}
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=1; i<n; i++){
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
        graph[end].push_back(start);
    }

     que.push(1);
     visited[1] = 1;
     BFS();

     for(int i=2; i<=n; i++){
	    cout  << result[i] << "\n";
     }

    return 0;
}
