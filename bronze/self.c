#include <stdio.h>
#include <string.h>
int hann(int n){
	int num = n;
	if(num < 10){
		num = num + num;
		return num;
	}
	else if(num < 100){
		num = num + num/10 + num%10;
		return num;
	}
	else if(num < 1000){
		num = num + num/100 + num%100/10 + num%100%10;
		return num;
		
	}
	else if(num < 10000){
		num = num + num/1000 + num%1000/100 + num%1000%100/10 + num%1000%100%10;
		if(num >10000){
			return 0;
		}
		return num;

	}
	else{
		return 0;
	}
}
int main(){
	int list[10000];
	memset(list, 0, sizeof(int)*10000);
	for(int i=0; i<10000; i++){
		int n;
		n = hann(i);
		list[n] = 1;
	}	

	for(int i=0; i<10000; i++){
		if(list[i] == 0){
			printf("%d\n", i);
		}
	}
}
