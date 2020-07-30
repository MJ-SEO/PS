#include <stdio.h>
int main() {
        int n=0, x=0;
        scanf("%d %d", &n, &x);

        for(int i=0; i<n; i++){
		int a=0;
		scanf("%d", &a);
	
		if(a<x){
			printf("%d ",a);
		}	
        }
        return 0;
}

