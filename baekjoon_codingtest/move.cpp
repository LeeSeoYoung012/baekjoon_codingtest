#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int candymap[1001][1001];
int check[1001][1001];
int main() {
	int n;
	int m;

//	cout << "hi";
	cin >> n;
	cin >> m;
	memset(candymap, 0, sizeof(candymap));
	memset(candymap, 0, sizeof(check));
	for (int i = 1; i <= n; i++) {
	for (int j = 1; j <=m; j++) {
	cin >> candymap[i][j];

	}
	}
	for (int i = 1; i <= n; i++) {
	for (int j = 1; j <=m; j++) {

	int res = max(check[i - 1][j - 1], max(check[i - 1][j], check[i][j - 1]));
	check[i][j] = res + candymap[i][j];
	}
	}
	cout << check[n][m] << endl;
	return 0;
}