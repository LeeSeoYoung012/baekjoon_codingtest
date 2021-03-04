/* 벽부수고 이동하기 2206번 */
#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
#include <stdio.h>
using namespace std;
int d[1005][1005];
int check[1005][1005][2];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

queue<tuple<int, int, int>> q;
int n, m;
int func(int x, int y, int br) {
	if (x == n && y == m) {
		if (d[x][y] == 1)return 0;
		else return 1;
	}
	q.push(make_tuple(x, y, br));
	check[x][y][br] = 1;
	while (!q.empty()) {
		x = get<0>(q.front()); 
		y = get<1>(q.front());
		br = get<2>(q.front()); //break를 이전에 했는지 안했는지가 영향을 주기 때문에 고려를 해야함.
		q.pop();
		for (int i = 0; i<4; i++) {
			int newx = x + dx[i]; int newy = y + dy[i]; int newbr = br; //br: break 했는지 안했는지
			if (newx >= 1 && newx <= n && newy >= 1 && newy <= m && newbr >= 0 && newbr <= 1) {

				if (check[newx][newy][newbr] == -1 && d[newx][newy] == 1 && newbr == 0) {

					newbr = br + 1;
					q.push(make_tuple(newx, newy, newbr));
					check[newx][newy][newbr] = check[x][y][br] + 1;
					if (newx == n && newy == m) {
						return check[newx][newy][newbr];
					}
				}
				else if (check[newx][newy][newbr] == -1 && d[newx][newy] == 0)
				{
					q.push(make_tuple(newx, newy, newbr));
					check[newx][newy][newbr] = check[x][y][br] + 1;
					if (newx == n && newy == m) {
						return check[newx][newy][newbr];
					}

				}
			}
		}
	}

	return -1;
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &d[i][j]);
		}
	}
	memset(check, -1, sizeof(check));
	int res = func(1, 1, 0);
	cout << res << "\n";
}