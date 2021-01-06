#include <stdio.h>

int m(int a, int b, int max){
	if(b>=a && b<=max){
		return b;
	}	
	else{
		return a;
	}
}

int main(){
	int n, Max;
	scanf("%d %d", &n, &Max);
	int max=0;
	int arr[n];

	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	
	int temp =0;

	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			for(int k=j+1; k<n; k++){
				temp = arr[i] + arr[j] + arr[k];
				printf("DEBUG temp: %d\n", temp);
				max = m(max, temp, Max);			
			}
		}
	}
	
	printf("%d", max);
}

