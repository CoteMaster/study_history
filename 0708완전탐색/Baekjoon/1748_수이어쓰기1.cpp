/**
1. 문제 그대로 입력받은값까지 for돌려서 string으로 변환후 붙인 다음
string 사이즈를 출력 -> 범위가 커서 메모리초과

2. 
1~9 => (9-1+1)*1
10~99 => (99-10+1)*10
이런식으로 계산해줌.

**/

#include <iostream>
using namespace std;

int main() {
	int n;
    cin >> n;
	long long ans = 0; 
	long long start = 1;
	long long length=1;
	
	while (start <= n){
		long long end = start*10-1;
		if (end>n) end=n;
		ans += (end-start+1)*length;
		start *= 10;
		length += 1;
	}
	
	cout <<ans<<'\n';
	return 0;
}
