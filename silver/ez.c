#include <stdio.h>


int main(){
        int a,b;
        scanf("%d %d", &a, &b);
	int sum=0;
	int start;
	start = b-a;
	
	for(int i=start; i<b; i++){
		sum+=i;
	}
        printf("%d", sum);
        
	return 0;
}

