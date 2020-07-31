#include <stdio.h>

int main(){
	int arr[10];
	int a=0;
	int result[10];
	int n=10;

	for(int i=0; i<10; i++){
		scanf("%d", &arr[i]);
	}
	for(int i=0; i<10; i++){
		a = arr[i]%42;
		result[i] = a;
	}
	for(int i=0; i<10; i++){
		for(int j=i+1; j<10; j++){
			if(result[i] == result[j]){
				n--;
				break;
			}
		}
	}	
	printf("%d", n);
	return 0;
}

