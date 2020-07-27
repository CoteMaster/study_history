#include<iostream>

using namespace std;


int memo[1010];

int Find_Num(int num);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	cout << Find_Num(n);

	return 0;
}

int Find_Num(int num)
{
	if (num == 1) return 1; //기저조건
	if (num == 2) return 3;
	if (memo[num]> 0) return memo[num];
	return memo[num] = ((Find_Num(num - 2) * 2) + Find_Num(num - 1)) % 10007;
}
