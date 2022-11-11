#include <iostream>
#include <algorithm>

using namespace std;

pair<int,int> arr[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	int n;
	cin >> n;
	int result = 0;

	for(int i=0; i<n; i++){
		cin >> arr[i].second >> arr[i].first;
	}

	sort(arr, arr+n);
	
	int t = 0;
	for(int i=0; i<n; i++){
		if(t > arr[i].second) continue;
		result++;
		t = arr[i].first;
	}

	cout << result;
     	return 0;
}


/*
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> arr;
int N;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int max_reserve = 0;

    for(int i=0; i<N; i++){
        int st, ed;
        cin >> st >> ed;
        arr.push_back({ed, st});
    }

    sort(arr.begin(), arr.end());

    vector<pair<int, int>> room;
    room.push_back(arr[0]);

    for(int i=1; i<N; i++){ 
        if(room[max_reserve].first <= arr[i].second){
            max_reserve += 1;
            room.push_back(arr[i]);
        }
    }

    cout << max_reserve+1 << "\n";
}
*/