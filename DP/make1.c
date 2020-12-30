#include <stdio.h>



int main(){
	int n;
	int re=0;
	scanf("%d", &n);
	
	while(n!=1){
		if(n%3==0){
			printf("%d번째인 %d는 3에 들림\n", re, n);
			n=n/3;
			printf("n: %d\n", n);
			re++;
		}
		else if(n%2==0){
			if((n-1)%3==0){
				printf("durl\n");
				n=n-1;
				re++;
			}
			else{
			printf("%d번째인 %d는 2에 들림\n", re, n);
			n=n/2;
			printf("n: %d\n", n);
			re++;
			}
		}
		else{
			printf("%d번째인 %d는 1에 들림\n", re, n);
			n=n-1;
			printf("n: %d\n", n);
			re++;
		}		
	}
	
	printf("%d\n", re);
}
