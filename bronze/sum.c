#include <stdio.h>
#include <string.h>

int main(){
	int n;
	char arr[100];
	memset(arr, 0, sizeof(char)*100);
	int result=0;
	scanf("%d", &n);
	
	scanf("%s", arr);	

	for(int i=0; i<n; i++){
		result += arr[i]-48;
	}

	printf("%d\n", result);
	return 0;
}
