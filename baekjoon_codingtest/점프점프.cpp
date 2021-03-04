#include <iostream>
#include <cstring>

using namespace std;


int main() {
	int n;
	int check[1001] = { 0, };
	check[1] = 1;
	cin >> n;
	int num;
	for (int i = 1; i <= n; i++) {
		cin >>num ;
		if (check[i] == 0) continue;
		for (int j = 1; (j <= num) && (i + j <= 1000); j++) {
			if (check[i + j] > check[i] + 1 || check[i + j] == 0) {
				check[i + j] = check[i] + 1;
			}
		}
	}
	
	if (check[n] == 0) { cout << -1 << endl; }
	else { cout << check[n] - 1 << endl; }
}