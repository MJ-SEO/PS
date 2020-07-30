#include <stdio.h>
int main(){
        unsigned int a,b,c;
	unsigned int result=0;
	unsigned int sum;
	unsigned int n=0;
	unsigned int profit;
        scanf("%d %d %d", &a, &b, &c);
	profit = c-b;

	if(b>=c){
		printf("-1");
		return 0;
	}
	
	n = a/profit+1;
        printf("%d", n);
        return 0;
}

