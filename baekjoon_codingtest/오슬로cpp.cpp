#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

string arr[8];
int tx[] = { 1,-1,1,-1,-1,1,0,0 };
int ty[] = { -1,1,1,-1,0,0,-1,1 };


int getcount(int nx, int ny, int dir)
{
	int num = 0;

	while (arr[nx][ny] == 'W')    //사이에 있던 백색은 모두 검은 색이 되어버린다. 
	{
		num++;
		nx += tx[dir];
		ny += ty[dir];
		if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8)
		{
			return 0;
		}
	}
	if (arr[nx][ny] == 'B')
	{
		return num;
	}
	return 0;
}



int main() {


	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int count = 0;


	for (int i = 0; i < 8; i++) {

		cin >> arr[i];

	}

	int maxn = 0;


	for (int p = 0; p <8; p++) {
		for (int q = 0; q<8; q++) {

			if (arr[p][q] != '.') {
				continue;
			}

			int cnt = 0;

			int x = p;
			int y = q;

			for (int j = 0; j < 8; j++) {

				int nx = x + tx[j];
				int ny = y + ty[j];


				if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {

					if (arr[nx][ny] != 'W') { continue; }

					cnt += getcount(nx, ny, j);

				}

			}


			if (maxn < cnt) { maxn = cnt; }


		}
	}


	cout << maxn << '\n';


}