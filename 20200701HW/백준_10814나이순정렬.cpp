#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct info {
	int age,num; string name;
	bool operator <(const info& a)const
	{
		if (age == a.age)
		{
			return num < a.num;
		}
		return age < a.age;
	}
};
vector<info>V;

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a; string na;
		cin >> a >> na;
		V.push_back({ a,i,na });
	}

	sort(V.begin(), V.end());

	for (int i = 0; i < V.size(); i++)
	{
		cout << V[i].age << " " << V[i].name << "\n";
	}
	return 0;

}
