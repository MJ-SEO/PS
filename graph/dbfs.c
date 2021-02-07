#include <stdio.h>
#include <stdlib.h>

void dfs(int start){
	printf("%d" ,start);
}

void bfs(int start){
	printf("%d" ,start);
}

typedef struct node{
	int vertex;
	int ** edge;
}node_t;

node_t * head = 0x0;

int main(){
	int n,m,v;
	scanf("%d %d %d" &n, &m, &v);


	dfs(v);
	bfs(v);

}
