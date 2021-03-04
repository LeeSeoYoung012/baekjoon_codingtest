#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int main() {

	int R, C, T;
	cin >> R;
	cin >> C;
	cin >> T;
	int arr[51][51];
	int check[51][51];
	int gi, gj;
	memset(arr, 0, sizeof(arr));
	memset(check, 0, sizeof(check));
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			
			cin>>arr[i][j];
			if (arr[i][j] == -1) { gi = i; gj = j; }
		}
	}

	for (int i = 0; i < T; i++) {

		for (int a = 0; a < R; a++) {
			for (int b = 0; b < C; b++) {
				
				if (arr[a][b] > 0) {
					int x = a;
					int y = b;
					for (int i = 0; i < 4; i++) {

						int nx = x + dx[i];
						int ny = y + dy[i];
						if (nx >= 0 && nx < R && ny >= 0 && ny < C) {

							if (arr[nx][ny] != -1) {

								check[nx][ny] += (arr[x][y] / 5);
								check[x][y] -= (arr[x][y] / 5);
							}

						}
						}
					}
			
				}}
	//	cout << endl;
		for (int p = 0; p < R; p++) {
			for (int q = 0; q < C; q++) {
				arr[p][q] += check[p][q];
		//	  cout << arr[p][q] << " ";
			}
	//		cout << endl;
		}
		arr[gi - 2][gj] = 0;
		int p;
		int q = 0;
		for ( p = gi - 2; p >0; p--) {
			swap(arr[p][q], arr[p - 1][q]);
		}
	

		 p = 0;
		for ( q = 0; q < C-1; q++) {
			swap(arr[p][q], arr[p][q + 1]);
		}
		 q = C-1;
		for ( p = 0; p < gi-1; p++) {
			swap(arr[p][q], arr[p + 1][q]);
		}
		 p = gi - 1;
		for ( q = C-1; q >1; q--) {
			swap(arr[p][q], arr[p][q-1]);
		}
		

		arr[gi + 1][0] = 0;
		 q = 0;
		for ( p = gi + 1; p < R-1; p++) {
			swap(arr[p][q], arr[p + 1][q]);
		
		}
		 p = R - 1;
		for ( q = 0; q < C - 1; q++) {
			swap(arr[p][q], arr[p][q+1]);

		}
		 q = C - 1;
		for ( p = R-1; p > gi; p--) {
			swap(arr[p][q], arr[p -1][q]);

		}
		 p = gi;
		for ( q = C-1; q > 1; q--) {
			swap(arr[p][q], arr[p][q - 1]);

		}

	/*	cout << endl;
		for (int p = 0; p < R; p++) {
			for (int q = 0; q < C; q++) {
				cout << arr[p][q] << " ";
			}
			cout << endl;
		}*/
		

		memset(check, 0, sizeof(check));
		}
	int total = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] == -1) { continue; }
			total += arr[i][j];
		}
	
	}
	cout << total <<endl;

}