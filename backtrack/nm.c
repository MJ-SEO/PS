#include <stdio.h>

int main(){
        int n, m;
        scanf("%d %d", &n, &m);
        int arr[n];

        for(int i=0; i<n; i++){
                arr[i] = i+1;
        }

	int temp = 0;

	do{
		int t=0;
		int n=0;
		while(t!=m){
			printf("%d ", arr[temp]); n++;
			if(n==m){
				printf("\n");
			}
			t++;
		}
		temp++;
	}while(temp!=n);
/*
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
*/
}
