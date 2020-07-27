#include<iostream>

using namespace std;

long memo[100];
void Find_N(int num);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	
	Find_N(N);

	cout << memo[N];
	return 0;
}

void Find_N(int num)
{
	memo[1] = memo[2] = 1;
	for (int i = 3; i <= num; i++)
		memo[i] = memo[i - 1] + memo[i - 2];
}
