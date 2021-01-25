#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
        int player;
	int cards = 3;
	char buf[128];
        scanf("%d", &player);
	int **arr;
	int *sum;
	arr = (int**)malloc(sizeof(int*)* player);
	sum = (int*)malloc(sizeof(int) * player);

	for(int i=0; i<player; i++){
		arr[i] = (int*)malloc(sizeof(int) * cards);
	}
	scanf("%c", buf);
        for(int i=0; i<player; i++){
		for(int j=0; j<3; j++){
			scanf("%d ", &arr[i][j]);
		}
        }
	for(int i=0; i<player; i++){
		for(int j=0; j<3; j++){
			sum[i] += arr[i][j];
		}
	}
	for(int k=0; k<player; k++){

	for(int i=0; i<3; i++){
		int temp = arr[k][i];
		for(int j=0; j<player; j++){
			if(k==j) continue;
//			printf("Temp: %d, arr[%d][%d]: %d\n", temp, j, i, arr[j][i]);
			if(temp == arr[j][i]){
//				printf("same\n");
				sum[k] -= arr[j][i];
				break;	
			}
		}
	}
	}
	for(int i=0; i<player; i++){
		printf("%d\n", sum[i]);
	}
}
