#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[] = { -1,1,0,0 }; //위,아래,왼,오
int dy[] = { 0,0,-1,1 };

int R, C;

void move(pair<int, pair<int, int> >arr[][102], pair<int, pair<int, int>>check) {
	pair<int, pair<int, int> >newarr[102][102];
	for (int i = 0; i <= R; i++) {
		for (int j = 0; j <= C; j++) {

			newarr[i][j] = check;
		}
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (arr[i][j] != check) {
				pair<int, pair<int, int>> elem = arr[i][j];
				int d = elem.second.second;
				int s = elem.second.first;
				int nx = i;
				int ny = j;
			//	cout << i << " " << j << endl;
				arr[i][j] = check;
				for (int t = 0; t < s; t++){
					if (d == 1) { //위
					
						if (nx <= 1) { d = 2; t--;  continue; }
						nx += dx[0];

						
					}
					else if (d == 2) {  //아래

						if (nx >= R) { d = 1; t--; continue; }
						 nx +=dx[1];
						
					}
					else if (d == 3) { //오른쪽
						if (ny >= C) {
							d = 4; t--; continue;
						}
						ny += dy[3];
					}
					else { //왼쪽
						if (ny <= 1) {
							d = 3; t--; continue;
						}
						ny += dy[2];
					}
			}
				if (newarr[nx][ny] != check) {
					
					if (newarr[nx][ny].first < elem.first) {
						elem.second.second = d;
						newarr[nx][ny] = elem;
					}
				
				}
				else { elem.second.second = d; newarr[nx][ny] = elem; }
				
			}
		
		}
	}
	for (int i = 0; i <= R; i++) {
		for (int j = 0; j <= C; j++) {

			arr[i][j] = newarr[i][j];
			//cout << arr[i][j].first << " ";
		
		}
	//	cout << endl;
	}
//	cout << endl;

}

int main() {

	int M;
	cin >> R;
	cin >> C;
	cin >> M;
	pair<int,pair<int,int>> arr[102][102];
	int s, d, z;
	int r, c;
	int sum = 0;
	pair<int, pair<int, int>> check = make_pair(-1, make_pair(-1, -1));
	for (int i = 0; i <= R; i++) {
		for (int j = 0; j <= C; j++) {
		
			arr[i][j] = check;
		}
	
	}
	for (int i = 0; i < M; i++) {
		cin >> r;
		cin >> c;
		cin >> s;
		cin >> d;
		cin >> z;
		arr[r][c]= make_pair(z, make_pair(s, d));
	}

	for (int j = 1; j <= C; j++) {
		for (int i = 1; i <= R; i++) {
		
			if (arr[i][j] != check) {
				sum += arr[i][j].first;
				arr[i][j] = check;
				break;
			}
		
		}
	
		
		move(arr,check);
		
	}

	cout << sum;

}