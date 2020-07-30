#include <stdio.h>
int main() {
        int middle=0;
	int a=0,b=0,c=0;
        
	scanf("%d %d %d", &a, &b, &c);
        
	if(a>=b && a<=c || a<=b && a>=c){
		middle = a;
	}
	else if(b<=a && b>=c || b>=a && b<=c){
		middle = b;
	}
	else{
		middle = c;
	}

	printf("%d", middle);
        return 0;
}
