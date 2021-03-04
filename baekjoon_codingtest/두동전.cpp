#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m;

int minnum = 10000;
int check[21][21][21][21];

bool over(int a, int b)     
{
	if (a < 0 || b < 0 || a >= n|| b >= m) return true;
	return false;
}



void find(char arr[][21],int x1, int y1, int x2, int y2, int count) {
	
	
	
	if (count > 10)
	{
		minnum = min(minnum, count);
		return;
	}
	if (minnum < count) { return; }
	
	if (over(x1, y1) == true && over(x2, y2) == true) return;   
	else if (over(x1, y1) == true && over(x2, y2) == false)    
	{
		if (minnum > count) { minnum = count; }
		return;
	}
	else if (over(x1, y1) == false && over(x2, y2) == true)     
	{
		if (minnum > count) { minnum = count; }
		return;
	}


	for (int i = 0; i < 4; i++) {
		int sx = x1 + dx[i];
		int sy = y1 + dy[i];
		int ex = x2 + dx[i];
		int ey = y2 + dy[i];

		
		if (arr[sx][sy] != '#' && arr[ex][ey]!='#') {
	
			find(arr, x1 + dx[i], y1 + dy[i], x2 + dx[i], y2 + dy[i], count + 1);
		
		}
		else if (arr[sx][sy] != '#' && arr[ex][ey] == '#') {
	
			find(arr, x1 + dx[i], y1 + dy[i], x2 , y2 , count + 1);
			
		}
		else if (arr[sx][sy] == '#' && arr[ex][ey] != '#') {
			
			find(arr, x1, y1 , x2 + dx[i], y2 + dy[i], count + 1);
		
		}
	
	}

	return;

}




int main() {

	cin >> n;
	cin >> m;
	char arr[21][21];
	int x1, y1;
	int x2, y2;
	int t = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'o') {
				if (t == 0) {
					x1 = i;
					y1 = j;
				}
				else {
					x2 = i;
					y2 = j;
				}
				t++;
			}
		}
	}
	
	find(arr, x1, y1, x2, y2, 0);
	if (minnum == 10000|| minnum>10) { cout << -1 << endl; }
	else{ cout << minnum << endl; }
}