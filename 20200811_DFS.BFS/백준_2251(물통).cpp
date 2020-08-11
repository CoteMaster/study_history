#include <iostream>
#include <queue>
using namespace std;

struct data {
	int a, b, c;
};

int A, B, C;
bool chk[202][202], ans[202]; // chk[a 물의 양][b 물의 양]

void bfs() {
	queue <data> q;
	q.push({0,0,C});
}

while (!q.empty()) {
	if (chk[sa][sb])
		continue;

	chk[sa][sb] = true;

	if (sa == 0)
		ans[sc] = true;

	//A > B
	if (sa + sb > B)
		q.push({ (sa + sb) - B, B, sc });
	else
		q.push({ 0, sa + sb, sc });

	//A > C
	if (sa + sc > C)
		q.push({ (sa + sc) - C, sb, C });
	else
		q.push({ 0, sb, sa + sc });

	//B > C
	if (sb + sc > C)
		q.push({ sa, (sb + sc) - C, C });
	else
		q.push({ sa, 0, sb + sc });

	//B > A
	if (sb + sa > A)
		q.push({ A, (sb + sa) - A, sc });
	else
		q.push({ sb + sa, 0, sc });

	//C > A
	//C > B
}
