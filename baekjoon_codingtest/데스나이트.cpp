#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int dx[] = { -2,-2,0,0,2,2 };
int dy[] = { -1,1,-2,2,-1,1 };

int n;


int bfs(int arr[200][200],int r1, int c1, int r2, int c2) {

	queue<pair<int, int>>q;
	q.push(make_pair(r1, c1));
	while (!q.empty()){
		
		int a, b;
		a = q.front().first;
		b = q.front().second;
		q.pop();
		for (int i = 0; i < 6; i++) {
			
			int nx = a + dx[i];
			int ny = b + dy[i];
			if (nx >= 0 && nx < n&& ny >= 0 && ny < n) {
				
				if (arr[nx][ny] == 0) {
					
					arr[nx][ny] = arr[a][b] + 1;
					if (nx == r2 && ny == c2) { return arr[nx][ny]; }
					q.push(make_pair(nx,ny));
				}
			
			}
		}
	
	}

	return -1;

}

int main() {

	cin >> n;
	int r1, c1, r2, c2;
	int arr[200][200];
	memset(arr,0,sizeof(arr));
	cin >> r1;
	cin >> c1;
	cin >> r2;
	cin >> c2;
	int answer = bfs(arr, r1, c1, r2, c2);
	cout << answer << endl;


}