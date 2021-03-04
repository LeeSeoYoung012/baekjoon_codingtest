#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};


int main() {

	int N, L, R;
	cin >> N;
	cin >> L;
	cin >> R;
	int arr[101][101];
	int check[101][101];
	memset(check, 0, sizeof(check));
	memset(arr, 0, sizeof(arr));
	for(int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin>>arr[i][j];
		}
	}
	int same = 0;
	int answer = 0;
	bool toggle = true;
	while (toggle) {
		same++;
		answer++;
		int sum = 0;
		queue<pair<int,int>>q;
		queue<pair<int, int> >group;
		toggle = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (check[i][j] == same) { continue; }
				q.push(make_pair(i, j));
				group.push(make_pair(i, j));
				check[i][j] = same;
				int sum = arr[i][j];
				
				while (!q.empty()) {

					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int i = 0; i < 4; i++) {
						int nx = x + dx[i];
						int ny = y + dy[i];
						if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
							int diff = abs(arr[x][y] - arr[nx][ny]);
							if (diff >= L && diff <= R) {
								
								if (check[nx][ny] != same) {
									toggle = true;
									check[nx][ny] = same;
									sum += arr[nx][ny];
									q.push(make_pair(nx, ny));
									group.push(make_pair(nx, ny));
								}

							}

						}
					}
				}
			//	if (toggle == false) { break; }
			//	else { answer++; }
				int avg = sum / group.size();
				while (!group.empty()) {
					int x= group.front().first;
					int y = group.front().second;
					arr[x][y] = avg;
					group.pop();
				}
		
			}
		}
	
	}
	cout << answer-1 << endl;

}



