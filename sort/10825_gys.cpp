#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef struct {
	string name;
	int g;
	int y;
	int s;
}stu;

bool 
cmp(const stu& a, const stu& b)
{
	if(a.g != b.g){
		return a.g > b.g;
	}
	else{
		if(a.y != b.y)
			return a.y < b.y;
		else{
			if(a.s != b.s)
				return a.s > b.s;
			else
				return a.name < b.name;
		}

	}
}

int main(){
	int n;
	cin >> n;

	stu* arr = (stu*)malloc(sizeof(stu)*n);

	for(int i=0; i<n; i++){
		string temp;
		cin >> temp;
		arr[i].name = temp;
		for(int j= 0; j<3; j++){
			int temp;
			cin >> temp;
			if(j==0)
				arr[i].g = temp;
			else if(j==1)
				arr[i].y = temp;
			else
				arr[i].s = temp;
		}
	}
/*
	for(int i=0; i<n; i++){
		cout << arr[i].name << " " << arr[i].g << " " << arr[i].y << " " << arr[i].s << "\n";
	}

	cout << "\n ============================ \n";
*/
	sort(arr, arr+n, cmp);
	
	for(int i=0; i<n; i++){
		cout << arr[i].name << "\n";
	}
	

	return 0;
}
