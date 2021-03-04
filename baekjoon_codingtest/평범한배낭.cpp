#include<iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int arr[101][100001];
int main() {
	int n;
	int weight;
	cin >> n;
	cin >> weight;
	memset(arr, 0, sizeof(arr));
	vector<pair<int,int>>things(100);


	for (int i = 1; i <= n; i++) {
		int w, v;
		cin >> w;
		cin >> v;
		things[i].first = w;
		things[i].second = v;
	
	}

	for(int i=1; i<=n; i++){
	
		int w,v;
		w = things[i].first;
		v = things[i].second;
		for (int j = 1; j <= weight; j++) {
			
			if (j >= things[i].first) {
				arr[i][j] = max(arr[i - 1][j], arr[i - 1][j - w] + v);
				//기존에 있는 값과 새로운 값을 서로 비교를 한다.
			}
			else {
				arr[i][j] = arr[i - 1][j];
			}
		}
	
	 }

	cout << arr[n][weight] << endl;



}