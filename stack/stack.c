#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	int s[10000];
	int size;
	int top;
}stack;

void init(stack* st){
	st->top = -1;
	st->size = 0;
}

void push(stack* st, int n){
	st->s[st->size] = n;
	st->size++;		
	st->top = st->s[(st->size)-1];
}

void pop(stack* st){
	if(st->size==0){
		printf("-1\n");
	}
	else{
		printf("%d\n", st->top);	
	}
	if(st->size==0){
		st->size = 0;
	}
	else{
		st->size--;
	}
	st->top = st->s[(st->size)-1];
}

void size(stack* st){
	printf("%d\n", st->size);
}

void top(stack* st){
	if(st->size==0){
		printf("-1\n");
	}
	else{
		printf("%d\n", st->top);
	}
}

int empty(stack* st){
	if(st->size == 0){
		printf("1\n");
	}
	else{
		printf("0\n");
	}
}

int main(){
	stack s;
	init(&s);
	
	char buf[128];
	int n;
	scanf("%d", &n);
	char com[15];	
	scanf("%c", buf);
	for(int i=0; i<n; i++)
	{
		scanf("%[^\n]", com);
		if(strstr(com,"push")){
			int num;
			for(int k=0; k<strlen(com); k++){
				if(atoi(com+k)!=0){
//					printf("atio: %d", atoi(com+k));
					num = atoi(com+k);
					break;	
				}
			}
			push(&s, num);
		}
		if(strstr(com,"pop")){
			pop(&s);
		}
		if(strstr(com,"size")){
			size(&s);
		}
		if(strstr(com,"empty")){
			empty(&s);
		}
		if(strstr(com,"top")){
			top(&s);
		}
		scanf("%c", buf);
	}
	return 0;
}

