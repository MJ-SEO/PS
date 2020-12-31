#include <stdio.h>

int main(){
	int day, night, tree;
	scanf("%d %d %d", &day, &night, &tree);
	int re=0;

	re = (tree - night -1) / (day-night) + 1;
	
	printf("%d\n", re);	
	return 0;
}
