#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int num=0;
	
	for(int i=0; i<n; i++){
		int a;
		scanf("%d", &a);
		if(a==2 || a==3 || a==5 || a==7){
			num++;
		}
		else if(a!=1){
			if(a%2!=0){	
				if(a%3!=0){
					if(a%5!=0){
						if(a%7!=0){
							num++;
						}
					}
				}
			}
		}
	}

	printf("%d", num);
}
