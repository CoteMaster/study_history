#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	vector<int> v;
	string str;
	cin >> str;

	for (int i = 0;i < str.length();i++) {
		v.push_back(str[i] - '0');
	}

	sort(v.begin(), v.end());

	for (int j = v.size()-1;j >= 0;j--) {
		cout << v[j];
	}
	return 0;
}
