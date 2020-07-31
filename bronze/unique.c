#include <stdio.h>
#include <string.h>

int main(){
        int n;
        scanf("%d", &n);
	int arr[n][2];

        for(int i=0; i<n; i++){
		for(int j=0; j<3; j++){
			scanf("%d", &arr[i][j]);
		}
        }
	int j=0;
	
	for(int i=0; i<5; i++){
		int num = arr[i][j];
		for(int k=0; k<5; k++){
			if(num==arr[k][j]){
				
			}
		}
		j++;
	}
	for(int i=0; i<3; i++){
		for(int j=0; j<n; j++){
			for(int k=0; k<n; k++){
				
			}
			arr[j][i] 		


			if(arr[j][i] == arr[j+1][i]){
				arr[j][i] = 0;
				arr[j+1][i] = 0;
			}		
		}
	}

	for(int i=0; i<n; i++){
		int sum=0;
		for(int j=0; j<3; j++){
			sum+=arr[i][j];
		}
		printf("%d\n", sum);
	}
}

