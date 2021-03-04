#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
using namespace std;
int n;




int main() {

		int check[100005][2];
		cin >> n;
		vector<int> expectroute;
		vector<vector<int>> v(n + 5);
		map<int, int> order;
		memset(check, -1, sizeof(check));
		int idx1;
		int	idx2;
		for (int i = 0; i < n - 1; i++) {
			cin >> idx1;
			cin >> idx2;
			v[idx1].push_back(idx2);
			v[idx2].push_back(idx1);
		}
		int route;
		for (int i = 0; i < n; i++) {
			cin >> route;
			expectroute.push_back(route);
		}
	
		vector<vector<int>> reallist(n + 5);
		vector<int> realroute;
		queue<int>q;
		q.push(1);
		check[1][1] = 1;    //level 체크
		check[1][0] = -1;   //부모 체크
		order[1] = 1;
	
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			realroute.push_back(x);
			int count = 1;
			for (int i = 0; i < v[x].size(); i++) {
				int nx = v[x][i];
				if (check[nx][1] == -1) {
					check[nx][0] = x;
					check[nx][1]= check[x][1]+1;
				//	order[nx]=count;
					q.push(nx);
					count++;
				}
			}
		
		}

		int level=1;
		int parentorder=1;
		int count = 1;
		for (int i = 0; i < n; i++) {

	if (check[expectroute[i]][1] > level) { level = check[expectroute[i]][1]; parentorder = 1; count = 1; }
			
			if (level != check[realroute[i]][1]) { 
				cout << 0 << endl; return 0;
			}
	
			
			order[expectroute[i]] = count;

			count++;

			int parent = check[expectroute[i]][0];

			if (parent == -1) { continue; }

			if (order[parent] < parentorder) { cout << parent <<order[parent] << " " << parentorder<<endl;  cout << 0 << endl; return 0; }
			else if (order[parent] > parentorder) { parentorder = order[parent]; }
			//cout << "hello"<<endl;
		}
		
		cout << 1 << endl; return 0;
	
	
}