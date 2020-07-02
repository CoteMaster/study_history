/**
재귀를 이용하여 idx를 ++해주면서 현재 값도 더한채로 다음꺼더하기/ 현재 값 빼준채로 다음꺼더하기 
**/

#include <iostream>
#include <vector>

using namespace std;

int n, goal;
int sum = 0;
int cnt = 0;
int arr[21];

void dfs(int sum, int idx) {
	sum += arr[idx];

	if (idx >= n)
		return;

	if (sum == goal)
		cnt++;

	dfs(sum, idx + 1);
	dfs(sum - arr[idx], idx + 1);
}

int main(){
	cin >> n >> goal;

	for (int i = 0; i < n;i++)
		cin >> arr[i];

	dfs(0, 0);

	cout << cnt <<'\n';

	return 0;
}
