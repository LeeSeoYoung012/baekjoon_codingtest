#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> dfs_order;
void dfs(bool *check, int x, vector<vector<int>>&v){
	
	check[x] = true;
	dfs_order.push_back(x);
	for (int i = 0; i < v[x].size(); i++) {
		if (check[v[x][i]] == false) {
			dfs(check, v[x][i], v);
		}
	}

	return;

}

int main() {

	int n;
	cin >> n;
	vector<vector<int>> v(n+1);
	vector<int>order(100002);
	bool check[100002] = {false,}; // 초기화 하는거 주의 !!
	for (int i = 0; i < n-1; i++) {
		int first;
		int second;
		cin >> first;
		cin >> second;
		v[first].push_back(second);
		v[second].push_back(first);
	}
	vector<int>b;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		b.push_back(tmp);
		order[b[i]] = i;//해당 노드가 몇번째 인지 저장
	}

	for (int i = 0; i < v.size(); i++) {
	
		sort(v[i].begin(), v[i].end(), [&](const int&u, const int&v) 
		{
			return order[u] < order[v];
		});
	}
	
	dfs(check, 1, v);

	if (dfs_order == b) { cout << 1 << endl; }
	else { cout << 0 << endl; }
	return 0;



}