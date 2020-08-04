#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);

	for(int i=0; i<n; i++){
		for(int j=(n*2)-1; j>i; j--){
			printf("*");
		}
		printf("\n");
		for(int k=0; k<=i; k++){
			printf(" ");
		}
	}
	
	printf("\n");

	for(int i=1; i<n ;i++){
		for(int j=2*i+1; j<=2*n+1; j++){
			printf("*");
		}
		printf("\n");
		for(int k=0; k<=i; k++){
			printf(" ");
		}
	}
	
	return 0;
}

