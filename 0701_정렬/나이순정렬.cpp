#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	struct info {
		int age, num; string name;
		bool operator <(const info& a)const
		{
			if (age == a.age)
			{
				return num < a.num;
			}
			return age < a.age;
		}
	};

	int tc, num;
	string name;
	cin >> tc;

	vector<info> people;

	for (int i = 0;i < tc;i++) {
		cin >>  num >> name ;
		people.push_back({ num,i,name });
	}
	sort(people.begin(), people.end());

	for (int i = tc;i<tc;i++) {
		cout << people[i].age << " " << people[i].name << '\n';
	}

	return 0;
}
