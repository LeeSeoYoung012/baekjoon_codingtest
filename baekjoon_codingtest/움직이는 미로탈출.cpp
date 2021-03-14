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
int dy[] = { 0,0,1,-1,-1,1,1,-1,0}; //comma �� �� ����...�ٺ���

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
		
			wall[i].first = x + 1;  // ���� �����ش�
		}
		else if (x + 1 >= 8) {
		//	arr[x][y] = '.';
			wall.erase(wall.begin()+i);  // �ǹٴڿ� ���� ���� ���� �����ش�
			i--; //�����ذ� �����ؼ� for������ ++ ���״ϱ� i �״�� ������Ű�� ���� -- ����
		}
	}


}

void simulate() {
	vector<vector<char>>v(8,vector<char>(8,'.'));
	for (int i = 0; i < wall.size(); i++) {
		
		v[wall[i].first][wall[i].second] = '#';   // ���� ��ġ ����Ʈ�� ���� �ٽ� arr�� �׷��ش�.(���� move�� ���� �ݿ���Ű�� ����)
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
	

		//���� ���� �����̰� ������ ��� �̾��� -> sec�� t�� ���� ������ (bfs level �� �޶��� ������) ���� �����̰� �ߴ�. 
		if (sec == t) { 
			move();     //���� ��ǥ�� �����ְ�
			simulate(); //���� arr�� �ݿ���Ų��. 
			t++;
		}

		if (arr[x][y] == '#') { //��ǥ�� �ٲ� �Ŀ� ���� ���� ��ġ�� ��ġ�� �ٷ� ������ ��
			continue;  }
		
		if (x == 0 && y == 7) { return 1; } //����

		for (int i = 0; i < 9; i++) { 

			int nx = x + dx[i]; 
			int ny = y + dy[i];  

			if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) { // �밢��,��,�Ʒ�,�¿�,�״�� 
				
				if (arr[nx][ny] == '.' && check[nx][ny][sec+1]==0) { // �������� �˻��Ѵ�,  �ش� ��ġ�� Ư���ð��� �湮�ߴ����� �����ش�.

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