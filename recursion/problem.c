#include <stdio.h>

int fx(int n){
	int sum = 0;
	while(n>10){
		while(n>10){
			sum += n%10;
			n = n/10;
		}
		fx(sum);	
	}

	return 0;
}

int main(){
	int n;
	int result;

	scanf("%d", &n);

	result = fx(n);

	printf("%d\n", n);

	if(result!=0){
		printf("YES");
	}
	else{
		printf("NO");
	}


}
