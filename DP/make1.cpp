#include <iostream>
#include <algorithm>

using namespace std;

int d[1000005];
int pre[1000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;	

	d[1] = 0;
	d[2] = 1;
	d[3] = 1;
	pre[2] = 1;
	pre[3] = 1;

	for(int i=4; i<=n; i++){
		d[i] = d[i-1] + 1;
		pre[i] = i-1;
		if(i%2 == 0 && d[i] > d[i/2] +1){
			d[i] = d[i/2] + 1;
			pre[i] = i/2;
		}
		if(i%3==0 && d[i] > d[i/3] + 1){
		 	d[i] = d[i/3] + 1;	   
		     	pre[i] = i/3;	
		}	
	}

	cout << d[n] <<"\n";

	int i = n;
	while(1){
		cout << i << " ";
		if(i==1) break;
		i = pre[i];
	}

	return 0;
}
