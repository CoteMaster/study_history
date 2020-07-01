#include <iostream>
#include <map>

using namespace std;

int main()
{
	int n;
	cin >> n;

	map<long long, int> m;

	while (n--)
	{
		long long num;
		cin >> num;
		m[num]++;
	}

	long long num;
	int count = 0;

	for (auto p : m)
	{
		if (count < p.second) {
			num = p.first;
			count = p.second;
		}
		else if (count == p.second && num > p.first)
			num = p.first;
	}
	cout << num << "\n";
}
