#include <stdio.h>

typedef struct node{
	int  a;
	struct node_t * next;
}node_t

int 
alloc_que(node_t * que){
	que = (node_t*)malloc(sizeof(node_t));
	node_t -> next = 0x0;
}

int 
enque(){

}

int
deque(){

}


int main(){
	node_t * que;
	que = alloc();

}
