#include <stdio.h>
int main() {
        int max=-1000000, min=1000000;
	int arr[1000000];
	int n=0;
        scanf("%d", &n);

	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	
	for(int i=0; i<n; i++){
        	int a=0;
		a = arr[i];
		if(a>max){
                	max = a;
        	}
        	if(a<min	){
                	min = a;
        	}
        }
	printf("%d %d", min, max);
        return 0;
}

