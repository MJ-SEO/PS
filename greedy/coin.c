#include <stdio.h>

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int coin[n];
	int result=0;	

	for(int i=0; i<n; i++){
		scanf("%d", &coin[i]);
	}	
	
	
	for(int i=n-1; i>=0; i--){
//	printf("befor k %d\n", k);
//	printf("coin[%d]: %d\n", i, coin[i]);
		result += k/coin[i];
		k = k%coin[i];
//	printf("after k %d\n", k);
	}
	
	printf("%d\n", result);
}


