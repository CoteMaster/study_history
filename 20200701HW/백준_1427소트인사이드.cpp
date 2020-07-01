#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>V;


int main()
{
	string N;
	string ans;
	cin >> N;

	
	for (int i = 0; i < N.length(); i++)
	{
		V.push_back(N[i]-'0');
	}

	sort(V.begin(), V.end());

	for (int i = V.size() - 1; i >= 0; i--)
	{
		ans += V[i] + '0';
	}
	cout << ans;

	return 0;
}
