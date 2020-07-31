#include <stdio.h>
#include <string.h>

int main(){
        int n;
        scanf("%d", &n);
        char str[20];

        for(int i=0; i<n; i++){
		int num;
                scanf("%d", &num);
		scanf("%s", str);
		printf("num: %d\n", num);
		printf("str: %s\n", str);
	
		for(int j=0; j<num; j++){
			char str2[20*num];
			str2 = strcpy(str2, str+j);
			
		}
        }
}

