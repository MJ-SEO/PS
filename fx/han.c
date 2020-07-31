#include <stdio.h>

int han(int a){
	if(a<100){
		return 1;
	}
	if((a/100 - a%100/10)==(a%100/10 - a%10)){
			return 1;
	}
	return 0;
}

int main(){
	int n;
	int sum=0;
	scanf("%d", &n);

	for(int i=1; i<=n; i++){
		int a=0;
		a = han(i);
		sum+=a;
	}
	
	printf("%d", sum);
}


