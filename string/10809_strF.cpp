#include <stdio.h>
#include <string.h>

int main(){
        char str[101];
        scanf("%s", str);
        int k=97;

        for(int i=0; i<26; i++){
                char* a;
                a = strchr(str, k);
                if(a>0){
                        printf("%ld ", a-str);
                }
                else{
                        printf("-1 ");
                }
                k++;
        }

        return 0;
}
