#include <stdio.h>

int result = 1;
int fac(int a){
	if(a==0){
		return 1;
	}
	result = result*a;
	a--;
	if(a==1){
		return result;	
	}
	fac(a);
}

int main(){
	int n;
	int a;
	scanf("%d", &n);
	a = fac(n);
	printf("%d", a);
	return 0;
}
