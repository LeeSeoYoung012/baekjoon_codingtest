#include<iostream>
#include <vector>
#include <queue>


using namespace std;
int n;
int arr[21][21];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool check[21][21];

typedef struct{
	
	int x;
	int y;
	int sz;
	int t;
	int cnt;

}info;

int bfs(info &baby, int tx, int ty) { //참조연산자가 훨씬 편하니까 참조연산자 쓸것
	
	queue<info>q;
	q.push(baby);
	memset(check, false, sizeof(check));
	vector<int>v;

	while (!q.empty()) {

		int x = q.front().x;
		int y = q.front().y;
		int sz = q.front().sz;
		int t = q.front().t;
		int cnt = q.front().cnt;
		
		q.pop();
		if (x == tx && y == ty) { baby = { x,y,sz,t,cnt };  return t; }

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < n && nx >= 0 && ny < n && ny >= 0) {
				
				if (arr[nx][ny] < sz && arr[nx][ny]!=0&& check[nx][ny]==false ) {
					
					if (sz == cnt + 1) { q.push({ nx, ny, sz + 1, t + 1,0 }); }
					else { q.push({ nx, ny, sz, t + 1,cnt+1 }); }
					check[nx][ny] = true;
				}
				else if (arr[nx][ny] == sz || arr[nx][ny] == 0) { //첨에 sz와 같을경우와 0일 경우를 안따짐
					if (check[nx][ny] == false) {
						q.push({ nx, ny, sz, t+1 ,cnt });
						check[nx][ny] = true;
					}
				}
			
			
			}
		
		}
	}
	return -1;

}


int main() {

	cin >> n;
	
	info baby;
	vector<info>fish;

	memset(check, false, sizeof(check));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				baby.x = i;
				baby.y = j;
				baby.sz = 2;
				baby.t = 0;
				baby.cnt = 0;
			}
			if (arr[i][j] >= 1 && arr[i][j] <= 6) {
				fish.push_back({i,j,arr[i][j],0,0});
			}
		}
	}




	while (!fish.empty()) {

		if (fish.size() == 1) {
			info finfo = fish.front();
			if (finfo.sz < baby.sz) {
				bfs(baby, finfo.x, finfo.y);

			}
			fish.pop_back();
		}
		else {

			int mindist = 9999;
			info minfish;
			info minbaby = baby;
			int minidx = -1;
	
			for (int i = 0; i < fish.size(); i++) {
				info test;
				info f = fish[i];
		
				test = baby;

				if (f.sz < baby.sz) {
				
					int aftersize = bfs(test, f.x, f.y);
					if (aftersize == -1) { continue; }
					int dist = aftersize;
					if (mindist > dist) {
						minfish = f;
						minbaby = test;
						minidx = i;
						mindist = dist;
			
					}
					else if (mindist == dist ) {
						if (minfish.x > f.x) {
							minfish = f;
							minbaby = test;
							minidx = i;
							mindist = dist;
			
						}
						else if (minfish.x == f.x) {
							if (minfish.y > f.y) {
								minfish = f;
								minbaby = test;
								minidx = i;
								mindist = dist;
			
							}
						}
					}
				}
			}

			if (minidx != -1) {
	
				fish.erase(fish.begin() + minidx);
				arr[baby.x][baby.y] = 0;
				arr[minbaby.x][minbaby.y] = 9; // 마지막에 이거 시작지점 안바꿔줘서 에러남
				baby = minbaby;
				arr[minfish.x][minfish.y] = 0;
				

			}
			else {
				break;
			}
		}

	}

	cout << baby.t << endl;




	

}