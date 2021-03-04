#include<iostream>
#include<vector>
#include<cstring>


using namespace std;
int wonpan[51][51];
int check[51][51];
int n, m, t;
int NON = 99999;

struct s {
	int x, d, k;
}spin[51];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
void clockwise(int wonpan[51][51] , int j){

	int tmp = wonpan[j][1];
	int next;
	for (int t = 1; t <= m; t++) {
		
		if (t == m) { wonpan[j][1] = tmp; break; }
		next = wonpan[j][t + 1];
		wonpan[j][t + 1]=tmp;
		tmp = next;
	
	}

}

void counterclockwise(int wonpan[51][51] , int j){
	
	int tmp = wonpan[j][m];
	int next;
	for (int t = m; t >= 1; t--) {
		
		if (t == 1) { wonpan[j][m] = tmp; break; }
		next = wonpan[j][t - 1];
		wonpan[j][t - 1] = tmp;
		tmp = next;
	}

}




void move(int i) {

	int d = spin[i].d;
	int k = spin[i].k; 
	int x = spin[i].x; //배수

	for (int j = 1; j <= n; j++) {

		if (j%x == 0) {
			for (int p = 0; p < k; p++) {

				if (d == 0) {
					clockwise(wonpan, j);
				}
				else {
					counterclockwise(wonpan, j);
				}
			}
		}
	}


}

//(i,j) -> (i,j-1), (i,j+1), (i+1,j),(i-1,j)
bool checksame() {

	bool toggle = false;
	for (int i = 1; i <=n; i++) {
		for (int j = 1; j <= m; j++) {
		
			int num = wonpan[i][j];

	
			if (wonpan[i][j]!=NON) {

				for (int k = 0; k < 4; k++) {

					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
						if (wonpan[nx][ny] == num) {
							check[nx][ny] = NON;
							check[i][j] = NON;
							toggle = true;
						}
					}

				}

				if (j == 1) {

					if (wonpan[i][m] == num) {
						check[i][m] = NON;
						check[i][j] = NON;
						toggle = true;
					}

				}
				else if (j == m) {

					if (wonpan[i][1] == num) {
						check[i][1] = NON;
						check[i][j] = NON;
						toggle = true;
					}

				}

			}

		
		}
	}

	return toggle;

	

}


double getavg() {
	
	double total = 0;
	double p = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (wonpan[i][j] != NON) {
				total += (double)wonpan[i][j];
				p++;
			}
		}
	}
	return total/p;
}

void calc() {

	double avg = getavg();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (wonpan[i][j] != NON) {
				if ((double)wonpan[i][j] > avg) {
					--wonpan[i][j];
				}
				else if ((double)wonpan[i][j] < avg) {
					++wonpan[i][j];
				}
			}
		}
	}

}


void erase() {
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
		
			if (check[i][j] == NON) {
				
				wonpan[i][j] = NON;

			
			}

		}
	}

}



int simulate() {

	int total = 0;
	for (int i = 1; i <=t; i++) {
	
		 move(i);
		 if (checksame() == false) calc();
		 else { erase(); memset(check, 0, sizeof(check)); }
	
	}

	for (int i = 1; i <=n; i++) {
		for (int j = 1; j <=m; j++) {
		
			if (wonpan[i][j] != NON) {
				total += wonpan[i][j];
			}
		}
	}
	return total;

}



//(i,j)  i번째 원판에 적힌 j번째 수의 위치
int main() {


	cin >> n >> m >> t;

	memset(wonpan, 0, sizeof(wonpan));
	memset(check, 0, sizeof(check));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
		
			cin>>wonpan[i][j];
		
		}
	}

	for (int i = 1; i <=t; i++) {
		
		s & sp = spin[i];
		cin >> sp.x >> sp.d >> sp.k;
	}

	cout << simulate() << endl;



}
