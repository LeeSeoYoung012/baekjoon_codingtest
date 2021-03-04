#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int dp[10001][4];


void solve(int n, int k) {


	if (dp[n][k]) { return; }
	for (int i = 4; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
		
			int sum = 0;
			if (j == 1) {
				dp[i][j] = 1;
				continue;
			}
			else {
				for (int m = 1; m <= j; m++) {
					sum += dp[i-j][m];
				}

			}
			dp[i][j] = sum;
		
		}
}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	memset(dp, 0, sizeof(dp));
	dp[1][1] = dp[2][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;
	cin >> n;
	vector<int>answer;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		
		solve(num,3);
		answer.push_back( dp[num][1] + dp[num][2] + dp[num][3]);
		}
	for (int i = 0; i < answer.size(); i++) {
	
		cout << answer[i] << endl;
	
	}
	return 0;
	}


