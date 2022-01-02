#include <stdio.h>

void sort(int arr[], int size){
	int temp;
	int j=0;
	for(int i=1; i<size; i++){
		temp = arr[i];
		for(j=i-1; j>=0 && arr[j] > temp; j--){
			arr[j+1] = arr[j];
		} 
		arr[j+1] = temp;
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	int result=0;

	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}	

	sort(arr, n);

//	1 + (1+2) + (1+2+3) + (1+ 2+ 3+ 3) + (1+ 2+ 3+ 3+ 4) 

	for(int i=0; i<n; i++){
		for(int j=0; j<i+1; j++){
			result += arr[j];
		}
	}	

	printf("%d", result);	
}
