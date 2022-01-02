#include <stdio.h>

int a = 0;

int fx(long int n){
	int sum = 0;
	if(n<10){
		if(n%3 == 0) return a;
		else return 0;
	}
	while(n>10){
		sum+=n/10;
		n %= 10;
	}
	sum += n;
	a++;
	fx(sum);
}

int main(){
	long int n;
	int result;

	scanf("%ld", &n);

	result = fx(n);

	printf("%ld\n", n);

	if(result!=0){
		printf("YES");
	}
	else{
		printf("NO");
	}


}
