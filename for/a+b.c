#include <stdio.h>
int main() {
        int n=0;
        scanf("%d", &n);

        for(int i=1; i<=n; i++){
		int a=0, b=0;
		scanf("%d %d", &a, &b);
		
		printf("Case #%d: %d + %d = %d\n", i,a,b,a+b);
        }
        return 0;
}

