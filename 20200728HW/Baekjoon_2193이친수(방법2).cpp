#include<iostream>

using namespace std;

long memo[100][2] = { {0,0},{0,1},{1,0} }; //0의값, 1의값
void Find_N(int num);

// 1
// 1 0
// 1 0 -> 1 or 0
// 1 0 1 -> 0 // 1 0 0 -> 1 or 0
// 뒤에 0이오는 경우와 1이오는 경우를 나눠서 생각해준다 --> 2차원배열에 메모이제이션

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	
	Find_N(N);

	cout << memo[N][0]+memo[N][1];
	return 0;
}

void Find_N(int num)
{
	for (int i = 3; i <= num; i++)
	{
		memo[i][0] = memo[i - 1][0] + memo[i - 2][0];
		memo[i][1] = memo[i - 1][0];
	}
}
