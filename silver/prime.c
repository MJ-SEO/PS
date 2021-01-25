#include <stdio.h>
   
int arr[1005];

int main()
{    
    int n,m;
    int p=0;
    scanf("%d %d", &n, &m);
   
    for(int i=2; i<=n; i++)
    {
        for(int j =1; j <= n; j++)
        {
            if(i*j <= n)
            {   
                if(arr[i*j] == 1)
                    continue;
                    
                arr[i*j] = 1;
                p++;
                    printf("순서 p:%d 값:%d\n",p, i*j);
                    if(p == m)
                        printf("%d\n", i*j);
            }
        }
    }
    return 0;
}
