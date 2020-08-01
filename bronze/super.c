#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
	int score[10];
	int stack[10];
	int sum=0;
	int min=1000;
	int num;
	int result;
	for(int i=0; i<10; i++){
		scanf("%d", &score[i]);
		sum+=score[i];
		stack[i] = sum;
		printf("stack[%d]: %d\n", i, stack[i]);	
	}
	
	for(int i=0; i<10; i++){
		printf("절대값: %d\n", abs(stack[i]-100));
		if(abs(stack[i]-100)<=min){
			min = abs(stack[i]-100);
			num = i;	
			printf("min: %d num: %d\n", min, num);
		}	
	}
	
	for(int i=0; i<=num; i++){
		result+=score[i];	
	}

	printf("%d", result);	
}
