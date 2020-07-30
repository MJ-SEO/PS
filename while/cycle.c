#include <stdio.h>

int main()
{
        int n=1;
	int input=0;
	scanf("%d", &input);
	int temp = input;
	int sum=0;	
	int new=0;
        while(1)
        {
		int a=0,b=0;
		a=temp/10;
		b=temp%10;
		sum = a+b;
		printf("%d %d %d\n", a,b,sum);
		new = (b*10)+(sum%10);
		if(new==input){
			break;
		}
		else{
			temp = new;
			n++;
		}
        }
        printf("%d\n", n);
        return 0;
}

