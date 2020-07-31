#include <stdio.h>

int main(){
        int a=0,b=0,c=0;
        scanf("%d %d %d", &a,&b,&c);
	int d = a*b*c;
	int i=0;
	int arr[10];
	int n0=0,n1=0,n2=0,n3=0,n4=0,n5=0,n6=0,n7=0,n8=0,n9=0;
	while(d!=0){
		int ying;
		ying = d%10;
		arr[i]=ying;
		d/=10;
		i++;
	}
	
	for(int j=0; j<i; j++){
		if(arr[j] == 0)
			n0++;
		else if(arr[j] == 1)
			n1++;
		else if(arr[j] == 2)
                        n2++;
		else if(arr[j] == 3)
                        n3++;
		else if(arr[j] == 4)
                        n4++;		
		else if(arr[j] == 5)
                        n5++;
                else if(arr[j] == 6)
                        n6++;
                else if(arr[j] == 7)
                        n7++;
                else if(arr[j] == 8)
                        n8++;
		else
			n9++;
	}	

        printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",n0,n1,n2,n3,n4,n5,n6,n7,n8,n9);

}
