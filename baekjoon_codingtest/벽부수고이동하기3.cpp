#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<queue>
#include<cstring>
#include<string>

using namespace std;
int n, m;
int map[1001][1001];
bool check[1001][1001][11]; //check에다가 count수를 더해주는 게 아니라 
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };


typedef struct  {

	int x;
	int y;
	int	br; 
	int nd;
	int dist;

}info;



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int wall;
	cin >> n;
	cin >> m;
	cin >> wall;

	memset(check, 0, sizeof(check));

	string s;

	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j] = s[j] - '0';
		}
	}
	queue<info> q;


	
	check[0][0][0]=true;

	q.push({0,0,0,0,1});
	int count = -1;

	

	while (!q.empty()) {
		
		int x = q.front().x;
		int y = q.front().y;
		int br = q.front().br;
		int nd = q.front().nd;
		int dist = q.front().dist;

		q.pop();

	//	cout << x << " " << y << " " << br << " " << check[x][y][br] << endl;

		if (x == n - 1 && y == m - 1) {
			count = dist;
			break;
		}
	
	//	cout<<check[x][y][br]<<endl;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				
			  if (map[nx][ny] == 1) {
				
					if ((br < wall) && (check[nx][ny][br + 1]==false)) {
						


						if (nd == 0) {
							check[nx][ny][br + 1] = true;
							q.push({nx,ny,br + 1 ,1,dist+1 });
						}
						else {
							
							q.push({ x,y,br,0,dist+1});
							
						}
					}
				
				}
				else {
					
					if (check[nx][ny][br] == false) {
						check[nx][ny][br] = true;
						
						if (nd == 0) {
							q.push({nx,ny,br,1,dist+1});
						}
						else {
							q.push({ nx,ny,br,0,dist+1 });
						}
					}
				}

			}
		}
	
	}

	cout << count ;
	return 0;

}