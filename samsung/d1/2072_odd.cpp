#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int trial;

	cin >> trial;

	for(int i=0; i<3; i++){
		int sum = 0;
		for(int i=0; i<10; i++){
			int temp;
			cin >> temp;
			if(temp%2 == 1){
				sum += temp;
			}
		}
		cout << "#" << i+1 << " " << sum << "\n";
	}

	return 0;
}

