#include <stdio.h>

int main(){
	int arr[8] = {0};
	for(int i=0; i<8; i++){
		scanf("%d", &arr[i]);
	}
	int n = 8;
	int m = 1;

	for(int i=0; i<8; i++){
		if(arr[i] != n){
			break;
		}	
		n--;
	}
	if(n==0){
	       	printf("descnding\n");
		return 0;
	}

	for(int i=0; i<8; i++){
		if(arr[i] != m){
			break;
		}	
		m++;
	}
	if(m==9){
		printf("ascending\n");
		return 0;
	}

	printf("mixed\n");
	return 0;
}
