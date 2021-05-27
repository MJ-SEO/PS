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
//	printf("[DEBUG] push: %d\n", n);	
	st->s[st->size] = n;
	st->size++;		
	st->top = st->s[(st->size)-1];
//	printf("[DEBUG] size: %d\n", st->size);	
}

int pop(stack* st){
	if(st->size==0){
		printf("-1\n");
		st->size = 0;
		return 0;
	}
	else{
		st->top = st->s[(st->size)-1];
//		printf("[DEBUG] pop: %d\n", st->top);
		st->size--;	
//		printf("[DEBUG] size: %d\n", st->size);
		return st->top;
	}
}

int size(stack* st){
	return st->size;
}

int main(){
	stack s;
	init(&s);
	
	int n;
	int sum=0;
	scanf("%d", &n);

	for(int i=0; i<n; i++)
	{
		int k;
		scanf("%d", &k);
		if(k!=0){
			push(&s, k);
		}
		else{
			pop(&s);
		}
	}
//	printf("[DEBUG] 최종 size: %d\n", size(&s));
	int sss = s.size;
	for(int i=0; i<sss; i++){	
		sum += pop(&s);
	}

	printf("%d\n", sum);
	return 0;
}
