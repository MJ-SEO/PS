#include <stdio.h>

int main(){
	int n, kim, lim;
	int result=1;

	scanf("%d %d %d", &n, &kim, &lim);
	while(n!=1){
	kim = kim/2+1;
	printf("kim: %d\n", kim);	
	lim = lim/2+1;
	printf("lim: %d\n", lim);	
	if(kim==lim){
		printf("re: %d\n", result);	
	}
	else{
		result++;
	}
		n=n/2;
	}
	return 0;
}
