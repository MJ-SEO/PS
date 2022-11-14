#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int day, night, height;
  cin >> day >> night >> height;

  cout << (height - night -1) / (day-night) + 1;

  return 0;
}