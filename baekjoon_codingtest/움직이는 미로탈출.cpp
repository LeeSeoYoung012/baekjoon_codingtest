#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>

using namespace std;


int n = 8; 
int m = 8;

int dx[] = { -1,1,0,0,1,1 ,-1,-1,0};
int dy[] = { 0,0,1,-1,-1,1,1,-1,0}; //comma 잘 좀 찍자...바보야

vector<vector<char>>arr(8, vector<char>(8));                //or vector
int check[9][9][100];
vector<pair<int, int>>wall;

typedef struct {

	int x;
	int y;
	int sec;

}info;

void move() {

	for (int i = 0; i < wall.size(); i++) {
		
		int x = wall[i].first;
		int y = wall[i].second;

		if (x + 1 <= 7) {
		
			wall[i].first = x + 1;  // 벽을 내려준다
		}
		else if (x + 1 >= 8) {
		//	arr[x][y] = '.';
			wall.erase(wall.begin()+i);  // 맨바닥에 있을 때는 벽을 없애준다
			i--; //없애준거 생각해서 for문에서 ++ 할테니까 i 그대로 유지시키기 위해 -- 해줌
		}
	}


}

void simulate() {
	vector<vector<char>>v(8,vector<char>(8,'.'));
	for (int i = 0; i < wall.size(); i++) {
		
		v[wall[i].first][wall[i].second] = '#';   // 벽의 위치 리스트를 보고 다시 arr을 그려준다.(벽이 move한 것을 반영시키기 위해)
	}
	arr = v;


}




int bfs(info p) {
	queue<info>q;
	q.push(p);
	int t = 1;
	while (!q.empty()) {


		int x = q.front().x;
		int y = q.front().y;
		int sec = q.front().sec;
		q.pop();
	

		//벽을 언제 움직이게 할지가 고민 이었음 -> sec가 t로 변할 때마다 (bfs level 이 달라질 때마다) 벽을 움직이게 했다. 
		if (sec == t) { 
			move();     //벽의 좌표를 내려주고
			simulate(); //직접 arr에 반영시킨다. 
			t++;
		}

		if (arr[x][y] == '#') { //좌표가 바뀐 후에 벽과 현재 위치와 겹치면 바로 끝나는 것
			continue;  }
		
		if (x == 0 && y == 7) { return 1; } //도착

		for (int i = 0; i < 9; i++) { 

			int nx = x + dx[i]; 
			int ny = y + dy[i];  

			if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) { // 대각선,위,아래,좌우,그대로 
				
				if (arr[nx][ny] == '.' && check[nx][ny][sec+1]==0) { // 벽인지를 검사한다,  해당 위치의 특정시간에 방문했는지를 따져준다.

					check[nx][ny][sec + 1] = 1; 
					q.push({ nx,ny,sec+1 });
					
				}
			}

		}
	}
	return 0;
}

int main() {
	
	memset(check, 0, sizeof(check));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			
			cin >> arr[i][j];
			if (arr[i][j] == '#') {
				wall.push_back(make_pair(i, j));
			}
		
		}
	}

	cout << bfs({7,0,0}) << endl;


}