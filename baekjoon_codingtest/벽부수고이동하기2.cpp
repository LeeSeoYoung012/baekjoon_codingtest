#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<queue>
#include<cstring>

//테스트 미통과 코드 
using namespace std;
int n, m,k;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

int arr[1000][1000];    //or vector
int check[1000][1000][10];	//or vector, or different type

int bfs(tuple<int,int,int>t, int k ) {
	
	queue<tuple<int, int,int>>q;
	q.push(t);
	check[get<0>(t)][get<1>(t)][get<2>(t)] = 1;

	while (!q.empty()) {
		
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int br = get<2>(q.front());
		q.pop();
		
		if (x == n-1 && y == m-1) {
			
			return check[x][y][br];
		
		}

		for (int i = 0; i < 4; i++) {
			
			int nx = x + dx[i];
			int ny = y + dy[i];
			int newbr = br;
			

			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (arr[nx][ny] == 0 && check[nx][ny][newbr] == 0){
					check[nx][ny][newbr] = check[x][y][br]+ 1;
					q.push({ nx,ny,newbr });
				}
				else if (arr[nx][ny] == 1 && check[nx][ny][newbr+1] == 0 && newbr<k){
				
					check[nx][ny][newbr + 1] = check[x][y][br]+1;
					q.push({ nx,ny,newbr + 1 });
			    }
			}
		}
	}

	return -1;
}



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> n;
	cin >> m;
	cin >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &arr[i][j]);
		}
	}
	
	cout<<bfs({ 0,0,0 },k)<<endl;

	return 0;

}

