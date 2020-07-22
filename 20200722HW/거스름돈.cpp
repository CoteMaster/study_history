#include<iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int remain, money, count = 0; 
	cin >> money;

	remain = 1000 - money;

	while (remain > 0)
	{
		if (remain >= 500)
		{
			remain -= 500;
			count++;
		}
		else if (remain >= 100)
		{
			remain -= 100;
			count++;
		}
		else if (remain >= 50)
		{
			remain -= 50;
			count++;
		}
		else if (remain >= 10)
		{
			remain -= 10;
			count++;
		}
		else if (remain >= 5)
		{
			remain -= 5;
			count++;
		}
		else if (remain >= 1)
		{
			remain -= 1;
			count++;
		}
	}

	cout << count;


	return 0;
}
