#include <stdio.h>

int main(){
	int n, k;
	scanf("%d", &n);
	char c[21]={0};

	for(int i=0; i<n; i++){
		scanf("%d", &k);
			
		scanf("%s", c);

		for(int j=0; j<k; j++){
			if(c[j]==0) break;			

			for(int m=0; m<k; m++){
				printf("%c", c[j]);
			}
		}
		printf("\n");
	}
}
