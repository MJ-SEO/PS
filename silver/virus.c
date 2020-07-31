#include <stdio.h>

struct comm{
	int num;
	int virus=0;
}

int main(){
        int com;
        scanf("%d", &com);
	int twin;
        scanf("%d", &twin);
	int arr[twin][2];

        for(int i=0; i<twin; i++){
		for(int j=0; j<2; j++){
                	scanf("%d %d", &arr[i][j]);
        	}
	}

		
}

