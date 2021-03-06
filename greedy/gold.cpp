#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
	return a > b;
}

int main(){
	ios::sync_with_stdio();
	cin.tie(0);

	int n;
	cin >> n;
	int result = 0;
	
	int* a1 = (int*)malloc(sizeof(int)*n);
	int* a2 = (int*)malloc(sizeof(int)*n);


	for(int i=0; i<n; i++){
		cin >> a1[i];		
	}
	
	for(int i=0; i<n; i++){
		cin >> a2[i];		
	}
	
	sort(a1, a1+n, cmp);
	sort(a2, a2+n);
	
	for(int i=0; i<n; i++){
		result += a1[i] * a2[i];		
	}
	
	cout << result << "\n";
}
