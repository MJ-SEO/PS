#include <stdio.h>
int main(){
        int kg=0;
        scanf("%d",&kg);
	
	int five=0, three=0;
	
        if(kg%3!=0 && kg%5!=0){
                printf("-1");
                return 0;
        }
	else if(kg%5==0){
		five = kg/5;
	}
	else if(kg%3==0){
		three = kg/3;
	}	
	else{
		five = 100;
		three = 100;
	}
        printf("%d\n", five+three);
        return 0;
}
