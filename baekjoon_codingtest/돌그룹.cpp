#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include<cstring>
using namespace std;



typedef struct {

	int a;
	int b;
	int c;

}st;


int main() {

	int arr[3];
	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
	}
	queue<st>q;
	set<pair<pair<int, int>, int>>check;

	q.push({arr[0],arr[1],arr[2]});
	check.insert({ {arr[0],arr[1]},arr[2] });
	while (!q.empty()) {
	
		int array[3];
		array[0] = q.front().a;
		array[1] = q.front().b;
		array[2] = q.front().c;
		q.pop();
		//cout << array[0]<<" "<< array[1] <<" "<< array[2] << endl;
		if (array[0] == array[1] && array[1] == array[2]) { cout << 1 << endl; return 0; }

		for (int i = 0; i < 3; i++) {
			for (int j = i; j < 3; j++) {
				if (array[i] != array[j]) {
					
					if (array[i] < array[j]) {
					
						int tmp = array[i];
						array[i] += array[i];
						array[j] = array[j]- tmp;
					
					}
					else {
						int tmp = array[j];
						array[j] += array[j];
						array[i]= array[i]- tmp; // tmp에 저장해놓을 것 
					
					}

					if (check.find({ {array[0],array[1]},array[2] }) == check.end()) {
					
						q.push({ array[0],array[1],array[2] });
						check.insert({ { array[0],array[1] },array[2] });
				
					}
					
				
				}
			}

		}
	
	}

	cout << 0 << endl;
	
	return 0;

}