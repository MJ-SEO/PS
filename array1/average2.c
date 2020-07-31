#include <stdio.h>
#include <string.h>

int main(){
        int n;
        scanf("%d", &n);
	float average;

        for(int i=0; i<n; i++){
		int stu=0;
		float good=0;
		float result=0;
		scanf("%d", &stu);
		float arr[stu];
		float sum=0;
		
		for(int j=0; j<stu; j++){
			scanf("%f", &arr[j]);
			sum+=arr[j];
		}
		
		average = sum/stu;

		for(int k=0; k<stu; k++){
			if(arr[k]>average){
				good++;	
			}
		}	

		result = good/stu*100;
		printf("%.3f%%\n", result);
        }
}

