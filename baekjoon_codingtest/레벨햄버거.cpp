#include<iostream>
#include<vector>
#include<cstring>
#include <string>

using namespace std;

int n;
long long x;

long long hb[51];
long long p[51];

long long find(int n, long long x) {

	if (x == 1) {
		return 0;
	}
	else if (x == hb[n - 1]) {
		return find(n - 1, x - 1);
	}
	else if (x == 1 + hb[n - 1] + 1)  //번, n-1 햄버거, 패티
		return p[n - 1] + 1;
	else if (x <= 1 + hb[n - 1] + 1 + hb[n - 1]) //번, n-1 햄버거, 패티 ,n-1 햄버거    
		return 1 + p[n - 1] + find(n - 1, x - 1);
	else
		return 2 * p[n - 1] + 1;


}





int main() {


	cin >> n;
	cin >> x;

	hb[0] = 1; //전체 재료 
	p[0] = 1;  //패티의 개수 

	for (int i = 1; i <= n; i++) {
		hb[i] = 1 + hb[i-1] + 1 + hb[i-1] + 1;
		p[i] = p[i - 1] + 1 + p[i];
	}

	
	cout << find(n,x)<<endl;
	return 0;
}
