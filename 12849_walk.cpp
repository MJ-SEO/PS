#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int Minute;
vector<int> graph[8];
queue<int> que;

void modeling(){
	graph[0].push_back(1); graph[0].push_back(2);
	graph[1].push_back(0); graph[1].push_back(2); graph[1].push_back(3);
	graph[2].push_back(0); graph[2].push_back(1); graph[2].push_back(3); graph[2].push_back(4);
	graph[3].push_back(1); graph[3].push_back(2); graph[3].push_back(4); graph[3].push_back(5);
	graph[4].push_back(2); graph[4].push_back(3); graph[4].push_back(5); graph[4].push_back(7);
	graph[5].push_back(3); graph[5].push_back(4); graph[5].push_back(6);
	graph[6].push_back(5); graph[6].push_back(7);
	graph[7].push_back(4); graph[7].push_back(6);
}

int BFS(){

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> Minute;
	modeling();

	que.push(0);

	for(int i=0; i<Minute; i+){
		int temp = que.front(); que.pop();	
	
	}


	return 0;
}

