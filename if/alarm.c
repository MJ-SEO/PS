#include <stdio.h>
int main() {
        int hour=0, minute=0;
	int sum=0;
        scanf("%d %d", &hour, &minute);
	sum = hour*60+minute;
	
	if(hour!=0){
		sum = sum-45;
		hour = sum/60;
		minute = sum%60;
	}
	else{
		if(minute>=45){
			hour = 0;
			minute = minute-45;
		}
		else{
			hour = 23;
			minute = minute+60-45;
		}
	}

	printf("%d %d", hour, minute);
        return 0;
}

