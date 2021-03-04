#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main() {
	int n, k;
	cin >> n;
	cin >> k;
	vector<int> v;
	int check[500][500];
	int num;
	memset(check, 0, sizeof(check));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			cin >> num;
			v.push_back(num);
		}

		for (int t = 0; t < k; t++) {
			check[0][t] = v[t];
		}
		for (int t = 0; t < k; t++) {
			for (int q = 0; q < k; q++) {
				int cand = check[0][t] + check[0][q];
				if (check[1][t] > cand) { check[1][t] = cand; }
			}
		}

		for (int p = 2; p <= k; p++) {
			for (int t = 0; t < k; t++) {
				for (int q = 0; q < k; q++) {

					int cand = check[p - 1][t]*2 + check[p - 1][q];
					if (check[p][t] > cand) { check[p][t] = cand; }
				}
			}
		}
	}
	return 0;

}