#include <stdio.h>
int main() {
        int max=0;
	int maxx=0;
        int arr[9];

        for(int i=0; i<9; i++){
                scanf("%d", &arr[i]);
        }

        for(int i=0; i<9; i++){
                int a=0;
                a = arr[i];
                if(a>max){
                        max = a;
			maxx=i+1;
                }
        }
        printf("%d\n%d", max, maxx);
        return 0;
}
