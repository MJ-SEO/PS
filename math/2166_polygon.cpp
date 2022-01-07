#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	double result = 0;
	int N;
	cin >> N;

	vector<pair<double, double>> coordinate;
	int tx, ty;

	for(int i=0; i<N; i++){
		int x, y;
		cin >> x >> y;
		coordinate.push_back({x, y});
		if(i==0) {
			tx = x;
			ty = y;
		}	
	}
	coordinate.push_back({tx, ty});

	for(int i=0; i<coordinate.size()-1; i++){
		result += coordinate[i].first * coordinate[i+1].second;
		result -= coordinate[i].second * coordinate[i+1].first;
	}
/*	double cx = 0;
	for(int i=0; i<coordinate.size()-1; i++){
		long double temp = coordinate[i].first * coordinate[i+1].second;
		cx += temp;
	}
	

	double cy = 0;
	for(int i=0; i<coordinate.size()-1; i++){
		double temp = coordinate[i].second * coordinate[i+1].first;
		cy += temp;
	}

	result = cx - cy;
*/
	cout << abs(result/2) << "\n";
	

	return 0;
}

