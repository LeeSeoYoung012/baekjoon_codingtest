#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include<cstring>
using namespace std;

int n, m;

int dx[] = { 1,2,3,4,5,6 };
int check[107];


int main() {
	cin >> n;
	cin >> m;
	int ls[105];

	memset(check,-1,sizeof(check));
	memset(ls, -1, sizeof(ls));
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x;
		cin >> y;
		ls[x] = y;
	}
	for (int j = 0; j < m; j++) {
		int x, y;
		cin >> x;
		cin >> y;
		ls[x] = y;
	}

	queue<int>q;
	q.push(1);
	check[1] = 0;
	bool toggle = false;
	while (!q.empty()) {
		int before = q.front();
		q.pop();
		for (int i = 0; i < 6; i++) {
			int now = before + dx[i];
			if (ls[now] != -1) {
				now = ls[now];
			}
			if (now <= 100 && check[now] == -1) {
				check[now] = check[before] + 1;
		
				if (now == 100) { cout << check[now] << endl; toggle = true; break; }
				q.push(now);
			}
		}
		if (toggle == true) { break; }

	}


}