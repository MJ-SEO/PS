#include <stdio.h>

long long sum(int *a, int n) {
	long long ans = 0;
	for(int i=0; i<n; i++){
		ans+=a[i];
	}
	return ans;
}

int main(){
	int summ=0;
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	
	summ = sum(arr, 5);
	
	printf("%d\n", summ);

	return 0;
}
