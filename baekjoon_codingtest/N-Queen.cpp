#include<iostream>
#include<vector>
#include <cstring>

using namespace std;

int n;
int dx[] = { 1,-1,0,0,1,1,-1,-1 };
int dy[] = { 0,0,-1,1,-1,1,-1,1 };
int answer = 0;


void find( int check[15][15], int count , int x) {

	if (count == n) { answer++; return; }

/*	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
		
			cout << check[i][j] << " ";
		
		}
		cout << endl;
	
	}


	cout << x << " " << endl;*/
	for (int y = 0; y < n; y++) {
	//	cout << "y:" << y <<endl;
		if (check[x][y]==0) {
			check[x][y] = 1;
			for (int i = 0; i < 8; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				while (nx >= 0 && nx < n && ny >= 0 && ny < n) {
					++check[nx][ny];
					nx = nx + dx[i];
					ny = ny + dy[i];

				}
			}
			find(check, count + 1, x + 1);
			check[x][y]--;
			for (int i = 0; i < 8; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				while (nx >= 0 && nx < n && ny >= 0 && ny < n) {
					--check[nx][ny];
					nx = nx + dx[i];
					ny = ny + dy[i];

				}
			}

			
		}
	}
			
		

	return;

}


int main() {

	int check[15][15];
	memset(check, 0, sizeof(check));
	cin >> n;
	find(check, 0,0);
	cout << answer<<endl;
}