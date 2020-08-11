#include<iostream>
#include<queue>
#include<set>

using namespace std;

struct info { int a, b, c; };

queue<info>Q;
set<int>result;
bool visit[210][210][210];
int A, B, C;

void BFS();

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> A >> B >> C;
	Q.push({ A,B,C });
	visit[A][B][C] = true;
	result.insert(C);

	BFS();

	set<int>::iterator it;
	for (it = result.begin(); it != result.end(); it++)
		cout << *it << " ";
	

	return 0;
}

void BFS() {

	while (!Q.empty()) {
		int a = Q.front().a;
		int b = Q.front().b;
		int c = Q.front().c;
		Q.pop();

		if (visit[a][b][c]) continue;
		if (a == 0)result.insert(c);
		//ac에 옮길때,
		//a->c
		int na = a;
		int nb = b;
		int nc = c;
		int initA = A;
		int initB = B;
		int initC = C;

		nc += na;
		na = 0;
		if (nc > initC) {
			initC = nc - initC;
			na = initC;
		}
		Q.push({ na,nb,nc });

		//c->a
		na = a;
		nb = b;
		nc = c;
		initA = A;
		initC = C;

		na += nc;
		nc = 0;
		if (na > initA) {
			initA = na - initA;
			nc = initA;
		}
		Q.push({ na,nb,nc });

		//b->c
		na = a;
		nb = b;
		nc = c;
		initB = B;
		initC = C;


		nc += nb;
		nb = 0;
		if (nc > initC) {
			initC = nc - initC;
			nb = initC;
		}
		Q.push({ na,nb,nc });


		//c->b
		na = a;
		nb = b;
		nc = c;
		initB = B;
		initC = C;

		nb += nc;
		nc = 0;
		if (nb > initB) {
			initB = nb - initB;
			nc = initB;
		}
		Q.push({ na,nb,nc });
		
		//a->b
		na = a;
		nb = b;
		nc = c;
		initA = A;
		initB = B;

		nb += na;
		na = 0;
		if (nb > initB) {
			initB = nb - initB;
			na = initB;
		}

		Q.push({ na,nb,nc });

		//b->a
		na = a;
		nb = b;
		nc = c;
		initA = A;
		initB = B;

		na += nb;
		nb = 0;
		if (na > initA) {
			initA = na - initA;
			nb = initA;
		}

		Q.push({ na,nb,nc });
		
	}

}
