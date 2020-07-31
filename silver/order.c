#include <stdio.h>

void insertion(int* arr, int n){
	int i,j,key;

	for(i=1; i<n; i++){
		key = arr[i];
		
		for(j=i-1; j>=0; j--){
			if(arr[j]>key){
				arr[j+1] = arr[j];
			}
			else{
				break;
			}
		}
		
		arr[j+1] = key;
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);	
	}

	insertion(arr, n);

	for(int i=0; i<n; i++){
		printf("%d\n", arr[i]);
	}
}

