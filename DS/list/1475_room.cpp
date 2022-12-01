#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

float freq[10];

int main(){
 	ios::sync_with_stdio(0);
 	cin.tie(0);	
	int result = 0;
	string room;
	cin >> room;
	
	for(auto e : room){
		if(e=='6' || e=='9'){
			freq[6]+= 0.5;
			freq[9]+= 0.5;

		}
		else{
			freq[e-48]+=1;
		}		
	}

	for(int i=0; i<10; i++){
		int temp = ceil(freq[i]);
		result = max(result, temp);
//		cout << freq[i] << " ";
	}
//	cout << "\n";

	cout << result;
	return 0;
}
