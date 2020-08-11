#include<iostream>
#include<cmath>
using namespace std;

int t;
struct dist { int x, y; };
dist info[110];

int main() {

	cin >> t;
	for (int q = 0; q < t; q++) {
		int n = 0;
		bool flag = false;
		cin >> n;
		
		for (int i = 0; i < n + 2; i++) {
			info[i] = { 0,0 };
		}
		for (int i = 0; i < n + 2; i++) {
			cin >> info[i].x >> info[i].y;
		}

		for (int j = 1; j < n + 2; j++) {
			int distcal = abs(info[j].x - info[j - 1].x) + abs(info[j].y - info[j - 1].y);
			if (distcal > 1000) {
				flag = true;
				cout << "sad\n";
				break;
			}
		}

		if (!flag) cout << "happy\n";
	}
	return 0;
}
