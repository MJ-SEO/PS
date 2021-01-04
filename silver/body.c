#include <stdio.h>
#include <string.h>

typedef struct{
	int w;
	int h;
	int num;
}man;

int main(){
	int n;
	scanf("%d", &n);
	man m[n];
			

	for(int i=0; i<n; i++){
		scanf("%d %d", &m[i].w, &m[i].h);
		m[i].num = 0;
	}

	for(int i=0; i<n; i++){
		int c=0;
		for(int j=0; j<n; j++){
			if(m[j].w > m[i].w && m[j].h > m[i].h){
				c++;
			}
		}
		printf("%d ", c+1);
	}

	return 0;	
}
