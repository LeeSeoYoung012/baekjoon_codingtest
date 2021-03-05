#include<iostream>
#include<vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <set>
using namespace std;

int n;
int m;

int check[1001][1001]; //전역변수로 1000*1000은 가능
int arr[1001][1001];
int dx[] = {1,-1,0,0};
int dy[] = { 0,0,1,-1 };

int bfs(int i, int j ,int idx) {

	queue<pair<int,int>>q;

	q.push(make_pair(i, j));
	check[i][j] = idx;
	int count = 1;

	while (!q.empty()) {

		int x = q.front().first;
		int y = q.front().second;
		q.pop();
	
		for (int i = 0; i < 4; i++) {
			
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			
				if (arr[nx][ny] == 0 && check[nx][ny]==0) {
					count++;
					check[nx][ny] = idx;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	
	return count;

}

void add_adj(vector<int>&cnts, pair<int, int>p) {

	int x = p.first;
	int y = p.second;

	set<int>s;

	for (int i = 0; i < 4; i++) {

		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (arr[nx][ny] == 0) {
				s.insert(check[nx][ny]);
			}
		}
	}
	int count = 1;
	for (int idx : s) {
		
		count += cnts[idx];
		
	}
	arr[x][y] = count%10;

}




int main() {

	cin >> n;
	cin >> m;


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]); //붙어있는 수를 따로 따로 받는 법 
		}
	}


	//플러드 필: cnts 배열에 각 빈칸 그룹의 연결된 영역 크기를 순서대로 저장
	vector<int> cnts(1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			if (arr[i][j] == 0 && check[i][j]==0) {
				
				cnts.push_back(bfs(i, j,cnts.size()));
			
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			if (arr[i][j] == 1) {
				add_adj(cnts, make_pair(i,j));
			}
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
	


	
	return 0;
}
