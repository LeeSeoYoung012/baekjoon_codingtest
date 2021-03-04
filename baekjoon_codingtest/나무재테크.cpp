#include<iostream>
#include<vector>
#include<cstring>
#include <algorithm>
using namespace std;
int N, M, K;
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };

int main() {
	int x, y, z;
	int a[11][11];
	int yangbun[11][11];
	vector<vector<vector<int>>>arr(11, vector<vector<int>>(11));
	cin >> N;
	cin >> M;
	cin >> K;
	memset(a, 0, sizeof(a));
	memset(yangbun, 0, sizeof(yangbun));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin>>a[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> x;
		cin >> y;
		cin >> z;
		arr[x-1][y-1].push_back(z);
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			yangbun[i][j] = 5;
		}
	}

	for (int p = 0; p < K; p++) {
		//봄,여름

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j].size() > 1) {
					sort(arr[i][j].begin(), arr[i][j].end());
				}
				if (arr[i][j].size() > 0) {
					int k = 0;
					while (yangbun[i][j] != 0 && k<arr[i][j].size()) {
						if (arr[i][j][k] <= yangbun[i][j]) {
							yangbun[i][j] -= arr[i][j][k];
							arr[i][j][k] += 1;
						}
						else {
							break;
						}
						k++;
					}
					int sz = arr[i][j].size();
					for (int t = 0; t < sz - k ; t++) {
						yangbun[i][j] += arr[i][j].back() / 2;
						arr[i][j].pop_back();
					}
				}
			}
		}

		//가을
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int t = 0; t < arr[i][j].size(); t++) {

					if (arr[i][j][t] % 5 == 0) {
						for (int l = 0; l < 8; l++) {
								int nx = i + dx[l];
								int ny = j + dy[l];
								if (nx < N && nx >= 0 && ny < N && ny >= 0) {
									arr[nx][ny].push_back(1);
								}
						}
					}
				}
			}
		}

		//겨울
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				yangbun[i][j] += a[i][j];
			}
		}

	}
	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			answer += arr[i][j].size();
		}
	}
	cout << answer << endl;

}