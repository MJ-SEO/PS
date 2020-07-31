#include <stdio.h>

float new(float score, int max){
	float result;
	result = score/max*100;
	printf("re: %f\n", result);
	return result;
}

int main(){
        float arr[1000];
        float n=0;
	int max=0;
        float sum=0;
	scanf("%f", &n);
        
	for(int i=0; i<n; i++){
        	float a;
		scanf("%f", &a);
		arr[i]=a;
        	if(arr[i]>max){
			max = arr[i];
		}
	}
	
        for(int i=0; i<n; i++){
        	arr[i] = new(arr[i],max);
		printf("arr[i]: %f\n", arr[i]);
		sum+=arr[i];
	}
        
	printf("%.2lf", sum/n);
        return 0;
}
