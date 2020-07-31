#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);

	for(int i=1; i<=2*n-1;i++){
		int j=0;
		if(j<i){
			for(int j=0; j<i; j++){
				printf("*");
			}
        		printf("\n");
		}
		else{
			for(int j=n; j<i; j++){
				printf("*");
			}
        		printf("\n");
		}
/*		if(i<n){
			for(int j=0; j<n; j++){
				printf("*");
			}
			
        	printf("\n");
		}
		else{
			for(int k=n-1; i<n; k++){
				printf("*");
			}	
        	printf("\n");
		}*/
	}

        return 0;
}

