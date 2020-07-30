#include <stdio.h>
	
int gcd(int a, int b){
	while(b!=0){
		int r = a%b;
		a= b;
		b= r;
	}
	return a;
}
int min(int a, int b){
	return a*b/gcd(a,b);
}
int main(){
	int n;
	scanf("%d", &n);
	int arr[1000];

	for(int i=0; i<n; i++){
		int a=0,b=0;
		int result=0;
		scanf("%d %d", &a, &b);
		result=min(a,b);
		arr[i] = result;
	}

	for(int i=0; i<n; i++){
		printf("%d\n", arr[i]);
	}
	return 0;
}
