#include <stdio.h>

int save[1000001];

int main(){

	int N,i;
	scanf("%d", &N);
	/*
	1. save[1,2,3]=1 저장
	2. i=4부터 N까지
		2-1. save[i]=save[i-1]
		2-2. i%3==0이라면 save[i]와 save[i/3]중 더 작은 것을 save[i]로 갱신 
		2-3. i%2==0이라면 save[i]와 save[i/2]중 더 작은 것을 save[i]로 갱신 
		2-4. save[i]++;
	3. save[N] 출력
	*/
	for(i=1;i<=3;i++) save[i]=1;
	for(i=4;i<=N;i++){
	//	printf("[DEBUG] save[%d]: %d\n", i, save[i]);
		save[i]=save[i-1];
		if(i%3==0&&save[i/3]<save[i]) save[i]=save[i/3];
		if(i%2==0&&save[i/2]<save[i]) save[i]=save[i/2];
		save[i]++;
		printf("[DEBUG] save[%d]: %d\n", i, save[i]);
	}
	printf("%d\n", save[N]);

}
