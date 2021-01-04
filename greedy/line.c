#include <stdio.h>
#include <string.h>

int main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	int line[n];
	memset(line, 0, sizeof(int) * n);	

	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	
	for(int i=0; i<n; i++){
		int k = 0;
		k += arr[i];
		int z=0;
		if(i==0){
			line[k] = i+1;
		}	
		else{	
			for(int j=0; j<n; j++){
				if(line[j] == 0 && k==0){
					line[j] = i+1;
					break;
				}
				else if(line[j] == 0){
					k--;
				}	
			}
		}

	}
	
	for(int i=0; i<n; i++){
		printf("%d ", line[i]);
	}
}
