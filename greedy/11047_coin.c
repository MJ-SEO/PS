#include <stdio.h>

int coin[15];

int main(){
	int n, k;
	scanf("%d %d", &n, &k);

	int result=0;	

	for(int i=0; i<n; i++){
		scanf("%d", &coin[i]);
	}	
	
	for(int i=n-1; i>=0; i--){
		result += k/coin[i];
		k = k%coin[i];
	}
	
	printf("%d\n", result);
}


