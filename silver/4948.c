#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int arr[250000] = {0};

void
set_arr(){
	arr[0] = 1;
	arr[1] = 1;

	for(int i=2; i<250000; i++){
		if(arr[i] == 0){
			for(int j=2; i*j <= 250000; j++){
				arr[i*j] = 1;
			}
		}	
	}

}

int prime(int n){
	int n_prime=0;
	for(int i=n; i<= (2*n); i++){
		if(arr[i] == 0){
			n_prime++;
		}
	}
	return n_prime;
}

int main(){
	int num = 0;
	set_arr();
	/*
	while(1){	
		scanf("%d", &num);
		if(num == 0) break;
		printf("%d\n", prime(num));
	};
	*/

	for(int i=0; i<20; i++){
		printf("arr[%d]: %d\n", i, arr[i]);
		if(arr[i] == 0){
			printf("DEBUG %d\n", i);
		}
	}
}
