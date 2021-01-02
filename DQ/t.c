#include <stdio.h>

void mm(int* a){
	*a += 5;
}

int main(){
	int n=0;
	printf("%d\n", n);	
	mm(&n);
	printf("%d\n", n);	
}
