#include<iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int n, m;
int bfs(vector<vector<int>>arr, vector<pair<int,int>>&virus) {

	queue<pair<int, int>>q;
	int count = 0;
	for (auto t : virus) {
		q.push(t);
		while (!q.empty()) {
		
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				
				int nx = x + dx[i];
				int ny = y + dy[i];
				if(nx>=0 && nx<n && ny>=0 && ny<m){
					
					if (arr[nx][ny] == 0) {
						arr[nx][ny] = 2;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
		
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
			   count++;
				
			}
		}
	}

	return count;

}





int main() {
	
	vector<vector<int>>arr(9,vector<int>(9,0));
	vector<pair<int, int> >virus;
	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				virus.push_back(make_pair(i, j));
			}
			
		}
	}

	int maxnum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			
			if (arr[i][j] == 0) {
				arr[i][j] = 1; 
			
			for (int k = i; k < n; k++) {
				for (int t = 0; t < m; t++) {
					if (arr[k][t] == 0) { 
						arr[k][t] = 1; 
					
					for (int l = k; l < n; l++) {
						for (int s = 0; s < m; s++) {
				
							if (arr[l][s] == 0) { 
							arr[l][s] = 1; 
							int safe = bfs(arr, virus);
							maxnum = max(maxnum, safe);
							arr[l][s] = 0;
						}
						
						}
					}
					arr[k][t] = 0;
				}

				}

			}
			arr[i][j] = 0;
		}
		
		}
	
	}
   cout<<maxnum<<endl;

	return 0;

}