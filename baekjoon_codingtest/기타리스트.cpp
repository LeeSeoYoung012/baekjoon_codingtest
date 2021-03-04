#include <iostream>
#include<cstring>
using namespace std;


int main() {

	int v[100];
	bool dp[101][1001];
	int n, s, m;
	
	memset(dp, false, sizeof(dp));
	cin >> n >> s >> m;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	dp[0][s] = true;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			
			if (dp[i - 1][j] == true) {
				int res = j + v[i - 1];
				if (res <= m) {
					dp[i][res] = true;
				}

				res = j - v[i - 1];
				if (res >= 0) {
					dp[i][res] = true;
				}
			}
		}
	
	}
	
	for (int i = m; i >= 0; i--) {
	
		if (dp[n][i] == true) {
			
			cout << i << endl;
			return 0;
		}
	}

	cout << -1 << endl;
	return 0;

}