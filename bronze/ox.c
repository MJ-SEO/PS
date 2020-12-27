#include <stdio.h>
#include <string.h>

int ap(int n){
	int num=0;
	while(n!=0){
		num += n;
		n--;
	}
	return num;
}

int main()
{
int n=0;
scanf("%d", &n);

for(int k=0; k<n; k++){
	char ox[80];
	int result = 0;
	int d=0;
	memset(ox, 0, sizeof(char)*80);
	scanf("%s", ox);	
		for(int i=0; i<80; i++){
			if(ox[i] == 'x' || ox[i] == 'X'){
				result += ap(d);
				d=0;
			} 
			else if(ox[i] == 'o' || ox[i] == 'O'){
				d++;
			}
			else{
				result += ap(d);
				break;
			}
		}
	printf("%d\n", result);	
}
}
