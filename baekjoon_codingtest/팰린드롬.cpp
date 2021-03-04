#include<iostream>
#include<vector>
#include<cstring>


using namespace std;

int check[2002][2002];
bool toggle = false;
int find(int *arr, int s, int f) {

	if (s == f) { return 1; }
	else {
	
		if (check[s][f] != -1) { return check[s][f]; }
		if (s + 1 == f && arr[s] == arr[f]) { return 1; }
		if (arr[s] != arr[f]) {
			return 0;
	}
	
	}
	 
	return check[s][f] =find(arr,s + 1, f - 1);
}



int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int arr[2002];
	
	for (int i = 1; i <=n; i++) {
		cin>>arr[i];
	}
	memset(check, -1 ,sizeof(check) );
	int m;
	cin >> m;
	int s, f;
	vector<int> answer;
	for (int j = 1; j <= m; j++) {
		cin >> s;
		cin >> f;
		answer.push_back(find(arr, s, f));

}

	for (int i = 0; i < answer.size(); i++) {
	
		cout << answer[i] ;
		cout << "\n";
	}
	return 0;
}