#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;


 struct horse{
	int x, y, d;

}h[10];


int dx[] = { 0,0,0,-1,1 };
int dy[] = { 0,1,-1,0,0 };   //오, 왼, 위, 아래 1,2,3,4
int inv[] = { 0,2,1,4,3 };

int n, k;
vector<int> info[13][13];
int chess[13][13];


int move(int i) {

//	horse& ho = h[i];
	int x = h[i].x;
	int y = h[i].y;
	int d = h[i].d;

	int nx = x + dx[d];
	int ny = y + dy[d];


	if (chess[nx][ny] == 2 || nx > n || nx <= 0 || ny > n || ny <= 0) {
		
		h[i].d = inv[d];

		nx = x + dx[d];
		ny = y + dy[d];

		if (chess[nx][ny] == 2 || nx > n || nx <= 0 || ny > n || ny <= 0) {
		
			return 0;
		
		}

	}

	vector<int> &cur = info[x][y];
	vector<int> &next = info[nx][ny];
	auto start = find(cur.begin(), cur.end(), i);
    
	if (chess[nx][ny] == 1){
		reverse(start, cur.end());
	}
   // next.insert(next.end(), start, cur.end());


	for (auto it = start; it != cur.end(); ++it)
	{
		h[*it].x = nx, h[*it].y = ny; // 옮겨준 말들의 좌표를 모두 갱신
		next.push_back(*it);
	}

	cur.erase(start, cur.end());
	return next.size();

}


int simulate() {
	int turn;
	for (turn = 1; turn <= 1000; ++turn){
		

		for (int i = 0; i < k; i++) {
		
			if (move(i) >=4) {
				return turn;
			}
		}
		
		//turn++;
	}

}


int main() {
	
	cin >> n;
	cin >> k;
	//memset(chess, 0, sizeof(chess));
	
	for (int i = 1; i <=n; i++) {
		for (int j = 1; j <=n; j++) {
			
			cin >> chess[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		
		horse & ho = h[i];
		cin >> ho.x >> ho.y >> ho.d;
		info[ho.x][ho.y].push_back(i); //말들을 각 위치 에 넣어준다. 
	}

	cout << simulate() << endl;
	return 0;


}