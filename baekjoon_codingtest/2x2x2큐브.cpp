#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

bool check(int l, int m, int n, int k) {
	

	if(l==m && m==n	&& n==k){ return true; }
	 return false; 
}


int main() {

	int arr[25];
	memset(arr, sizeof(arr), 0);
	for (int i = 0; i < 24; i++) {
		cin >> arr[i+1];
	}



	 if (check(arr[5], arr[6], arr[7], arr[8]) 
		 && check(arr[21], arr[22], arr[23], arr[24])
		 && check(arr[1], arr[2], arr[16], arr[14])
		&& check(arr[3], arr[4], arr[18], arr[20])
		&& check(arr[17], arr[19], arr[11], arr[12])
		&& check(arr[9], arr[10], arr[13], arr[15])) {
		cout << 1 << endl;
		}
	 else if (check(arr[5], arr[6], arr[7], arr[8])
		 && check(arr[21], arr[22], arr[23], arr[24])
		 && check(arr[1], arr[2], arr[17], arr[19])
		 && check(arr[9], arr[10], arr[18], arr[20])
		 && check(arr[14], arr[16], arr[11], arr[12])
		 && check(arr[3], arr[4], arr[13], arr[15])) {
		 cout << 1 << endl;
	 }

	else if (check(arr[13], arr[14], arr[15], arr[16])
		&& check(arr[1], arr[3], arr[21], arr[23])
		&& check(arr[5], arr[7], arr[2], arr[4])
		&& check(arr[9], arr[11], arr[6], arr[8])
		&& check(arr[22], arr[24], arr[10], arr[12])
		&& check(arr[17], arr[18], arr[19], arr[20])) {
		cout << 1<<endl;
	}
	else if (check(arr[13], arr[14], arr[15], arr[16])
		&& check(arr[1], arr[3], arr[6], arr[8])
		&& check(arr[5], arr[7], arr[10], arr[12])
		&& check(arr[9], arr[11], arr[21], arr[23])
		&& check(arr[22], arr[24], arr[2], arr[4])
		&& check(arr[17], arr[18], arr[19], arr[20])) {
		cout << 1<<endl;
	}
	else if (check(arr[1], arr[2], arr[3], arr[4])
		&& check(arr[13], arr[14], arr[7], arr[8])
		&& check(arr[5], arr[6], arr[19], arr[20])
		&& check(arr[17], arr[18], arr[23], arr[24])
		&& check(arr[21], arr[22], arr[15], arr[16])
		&& check(arr[9], arr[10], arr[11], arr[12])) {
		cout << 1 <<endl;
	}
	else if (check(arr[1], arr[2], arr[3], arr[4])
		&& check(arr[17], arr[18], arr[7], arr[8])
		&& check(arr[21], arr[22], arr[19], arr[20])
		&& check(arr[13], arr[14], arr[23], arr[24])
		&& check(arr[5], arr[6], arr[15], arr[16])
		&& check(arr[9], arr[10], arr[11], arr[12])) {
		cout << 1<<endl;
	}
	
	else {
		cout << 0<<endl;
	}
}
