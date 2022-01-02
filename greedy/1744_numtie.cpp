#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[10005];
vector<int> negative;
vector<int> positive;
vector<int> result;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int zero = 0;
	long long res = 0;
	cin >> n;

	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	for(int i=0; i<n; i++){
		if(arr[i] > 0){
			if(arr[i] == 1){
				result.push_back(arr[i]);	
			}
			else{
				positive.push_back(arr[i]);			
			}
		}
		else if(arr[i] == 0){
			zero++;
		}
		else{
			negative.push_back(arr[i]);
		}
	}

	sort(positive.begin(), positive.end(), greater<int>());
	sort(negative.begin(), negative.end());

	int psize = positive.size();
	for(int i=0; i<psize; i++){
		if(i == psize - 1){
			result.push_back(positive[i]);
		}
		else{
			result.push_back(positive[i] * positive[i+1]);
			i++;
		}		
	}

	int nsize = negative.size();
	if(zero > 1 && (nsize % 2 == 1)){
		negative.push_back(0);	
	}	

	for(int i=0; i<nsize; i++){
		if(i == nsize - 1){
			result.push_back(negative[i]);
		}
		else{
			result.push_back(negative[i] * negative[i+1]);
			i++;
		}		
	}
	
	for(int i=0; i<result.size(); i++){
		res+=result[i];
	}
	
	cout << res << "\n";
	return 0;
}

