#include<stdio.h>
#include<stdlib.h>

int main() {
	int m, n, i, j;
	int* arr;
	scanf("%d%d", &m, &n);
	arr = (int*)malloc(sizeof(int) * (n+10));
	for (i = 0; i <= n; i++) {
		arr[i] = 1;
	}

	arr[0] = 0;
	arr[1] = 0;

	for (i = 2; i <= n; i++) {
		if (arr[i]) {
			for (j = 2; i * j <= n; j++) {
				arr[i * j] = 0;
			}
		}
	}
	for (i = m; i <= n; i++) {
		if (arr[i] != 0)
			printf("%d\n", i);
	}
}
/*
int arr[100005];

void prime(int n){
	for(long long i=2; i*i < n; i++){
		if(arr[i] == 0){
			for(long long j = i*i; j<n; j=j+i){
				arr[j] = 1;
			}
		}
	}
*/
