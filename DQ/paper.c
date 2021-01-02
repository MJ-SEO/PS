#include <stdio.h>

int half(int p[][], int n, int* bule, int* white){
	이차워배열이 전부 1이거나 0이면
	 리턴 1(blue)
	 리턴 2(white)
	
	아니면
	재귀함수...
	 리턴 0
}

int main(){
	int n;
	scanf("%d", &n);
	char buf[128];
	scanf("%c", buf);
	
	int blue=0;
	int white=0;

	char paper[n][n];
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%c ", &paper[i][j]); 
		}
	}
	
	
	
}
