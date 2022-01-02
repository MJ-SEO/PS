#include <iostream>
#include <stack>
#include <vector>
#include <string.h>

using namespace std;

int main(){
	int n;
	string buf;
	cin >> n;
	stack<int> st;
	vector<char> result;

	getline(cin, buf);

	int arr[n];

	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}

	int j = 0;
	for(int i=1; i<=n; i++){
		st.push(i);
		result.push_back('+');
		
		while(!st.empty() && st.top() == arr[j]){
			st.pop();
			result.push_back('-');
			j++;
		}
	}

	if(!st.empty()) printf("NO\n");
	else{
		for(int i=0; i<result.size(); i++){
			printf("%c\n", result[i]);
		}
	}
/*	
		for(int j=0; j<n; j++){
			if(st.top() == list[i]){
				st.pop();
				break;
			}
			
			if(list[i] > k){
				if(스택에 없으면){
					st.push(k);
				}
			}
			else if(list[i] == k){   // top을 봐야?
				st.push(k)
				st.pop();
				break;
			}
			else{

			}
		}
	}
*/
	return 0;
}
