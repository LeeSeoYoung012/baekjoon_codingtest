#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int maxnum = 0;
int n;
void findmax(int*goosle, vector<bool>&check,int energy, int sz) {

	if (sz == 2) { if (maxnum < energy) { maxnum = energy; } return; }
	for (int i = 1; i < n-1; i++) {
		
		if (check[i] == false) {
			check[i] = true;
			int j = i;
			int prev = 0;
			int next = 0;
			while (j >= 0) {
				if (check[j] == false) { prev = goosle[j]; break; }
				j--;
			}
			j = i;
			while (j < n) {
				if (check[j] == false) { next = goosle[j]; break; }
				j++;
			}
			int getenergy = prev * next;
			findmax(goosle, check, energy + getenergy, sz - 1);
			check[i] = false;
		}
	
	}

	return;
}



int main() {
	
	int goosle[11];
	vector<bool>check(11, false);
	cin >> n;
	for (int i = 0; i < n; i++) {
	
		cin >> goosle[i];
	}

	findmax(goosle, check, 0, n);
	cout << maxnum << endl;

}