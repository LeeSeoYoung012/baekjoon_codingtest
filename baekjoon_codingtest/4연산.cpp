#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>

using namespace std;

//1�ð� 54�� 
// �ʹ� �������µ��� �ð� ����� -> ó�� s push �Ҷ� check ��Ͼ����༭ ��� Ʋ��, type longlong �����༭ Ʋ���⵵��

int main() {
	
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	queue<long long>q;
	map<long long, string>check;

	long long s;
	long long t;

	cin >> s;
	cin >> t;

	if (s == t) { cout << "0" << '\n'; return 0; }

	q.push(s);
	bool ans = false;
	check[s] = "s";  // �̷��� �Ǽ� �������� �ٺ���...

	while (!q.empty()) {

		long long num = q.front();
		q.pop();

		if (num == t) { ans = true;  break; }
		

		long long c =0;

		c = num*num; 
	
		if (check[c].empty()) {
			check[c] = check[num];
			if (check[c] == "s") { check[c].clear(); }
			check[c] += "*";
			q.push(c);
		}

		c = num + num;

		if (check[c].empty()) {
			check[c] = check[num];
			if (check[c] == "s") { check[c].clear(); }
			check[c] += "+";
			q.push(c);

		}

		c = num - num;

		if (check[c].empty()) {
			check[c] = check[num];
			if (check[c] == "s") { check[c].clear(); }
			check[c] += "-";
			q.push(c);
		}

		if (num != 0) {
			c = num / num;
			if (check[c].empty()) {
				check[c] = check[num];
				if (check[c] == "s") { check[c].clear(); }
				check[c] += "/";
				q.push(c);
			}
		}

	}

	if (ans == false) { cout << "-1" << endl; return 0; }
	
	cout << check[t];

	cout << '\n';
	return 0;

}