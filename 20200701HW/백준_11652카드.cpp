#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

map<long long,int>M;
bool cmp(const pair<long long, int>& a, const pair<long long, int>& b)
{
	if (a.second == b.second)return a.first < b.first;
	return a.second > b.second;
}

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		long long a; 
		cin >> a;
		M[a]++;
	}

	vector<pair<long long, int>>V(M.begin(), M.end());
	sort(V.begin(), V.end(), cmp);

	cout << V[0].first;
	return 0;
}
