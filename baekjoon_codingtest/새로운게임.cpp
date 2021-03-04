
#include <iostream>
#include <cstring>
#include <vector>
#include <deque>
#include<algorithm>
#include<map>
using namespace std;


int dx[] = { 0,0,-1,1 }; // 오,왼 , 위,아래
int dy[] = { 1,-1,0,0 };

int n, k;

void simulation(vector<vector<vector<pair<int, int>>>>& horseloc,int chess[13][13]){
	

	map<int, bool>m;
  for (int t = 1; t <= k; t++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < horseloc[i][j].size(); k++) {
					
					bool toggle = false;
					if (horseloc[i][j][k].first == t && m[t]==false) {

						toggle = true;
						if (k > 0) {
							
							m[t] = true;
					}
						else {
						
							int x = i;
							int y = j;
					

							vector<pair<int, int>>v = horseloc[x][y];
							pair<int, int> l = v[0];

							int nx = x + dx[l.second - 1];
							int ny = y + dy[l.second - 1];

							if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
								if (chess[nx][ny] == 0) {
									vector<pair<int, int>> nv = horseloc[nx][ny];
									nv.insert(nv.end(), v.begin(), v.end());   // 두개벡터 합치기
									horseloc[nx][ny] = nv;
									horseloc[x][y].clear();
									m[t] = true;
									
								}
								else if (chess[nx][ny] == 1) {
									vector<pair<int, int>>nv = horseloc[nx][ny];
									reverse(v.begin(), v.end());  //역순으로 바꿔준다.
									nv.insert(nv.end(), v.begin(), v.end());
									horseloc[nx][ny] = nv;
									horseloc[x][y].clear();
									m[t] = true;
								}
								else {


									int way = v[0].second;
									if (way == 1) {
										v[0].second = 2;
									}
									else if (way == 2) {
										v[0].second = 1;

									}
									else if (way == 3) {
										v[0].second = 4;
									}
									else {
										v[0].second = 3;
									}

									horseloc[x][y] = v;

									int nx = x + dx[v[0].second - 1];
									int ny = y + dy[v[0].second - 1];

									if (nx < 0 || nx >= n || ny < 0 || ny >= n || chess[nx][ny] == 2) {
										m[t] = true;
									}

								}

							}
							else {

								for (int i = 0; i < v.size(); i++) {

									int way = v[i].second;
									if (way == 1) {
										v[i].second = 2;
									}
									else if (way == 2) {
										v[i].second = 1;

									}
									else if (way == 3) {
										v[i].second = 4;
									}
									else {
										v[i].second = 3;
									}
								}

								horseloc[x][y] = v;

								int nx = x + dx[v[0].second - 1];
								int ny = y + dy[v[0].second - 1];

								if (nx < 0 || nx >= n || ny < 0 || ny >= n|| chess[nx][ny]==2) {
									m[t]=true;
								}

							}
						
						}
					}
					if (m[t] == false && toggle == true) { k--; }
				
				}
				}
			}
			
	}


}

bool totalfour(vector<vector<vector<pair<int, int>>>>&horseloc) {


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			
			if (horseloc[i][j].size()==k) {
				return true;
			}
			
		}
	}

	return false;
}



int main() {

	int chess[13][13];

	vector<pair<int, pair<int, int>>>next;
	vector<vector<vector<pair<int, int>>>>horseloc(13, vector<vector<pair<int, int>>> (13));

	cin >> n;
	cin >> k;


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin>>chess[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
	
		int x, y,way;
		cin >> x >> y;
		cin >> way;

		pair<int, int> p = make_pair(i + 1, way);
	    horseloc[x - 1][y - 1].push_back(p);
	
	}

	// 위, 아래 , 왼,오
	int turn = 1;

	while (turn<=1000) {
	
		simulation(horseloc, chess);
		if (totalfour(horseloc)) {
			cout << turn << endl;
			return 0;
		}
	    
		turn++;
	}

	cout << -1 << endl;
	return 0;



}