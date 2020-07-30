#include <stdio.h>
int main() {
	int min1=2001, min2=2001;
        int sum=0;

        for(int i=0; i<3; i++){
		int a;
                scanf("%d", &a);
                if(a<min1){
                        min1 = a;
                }
        }

        for(int i=0; i<2; i++){
		int a;
                scanf("%d", &a);
                if(a<min2){
                        min2 = a;
                }
        }
        sum=min1+min2;
	printf("%d", sum-50);
        return 0;
}

