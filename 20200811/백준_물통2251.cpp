#include<iostream>
#include<queue>
#include<set>


using namespace std;

struct info { int a, b, c; };

queue<info>Q;
set<int>result;
bool visit[250][250][250];
int A, B, C;

void BFS();

int main() {

	
	cin >> A >> B >> C;
	Q.push({ A,B,C });
	visit[A][B][C] = true;
	result.insert(C);

	BFS();

	std::set<int>::iterator it;
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
        
		if (a == 0)result.insert(c);
		
        //ac에 옮길때,
		if (!(a==0&&c==0))
		{
			//a->c
			int na = a;
			int nb = b;
			int nc = c;
			int initA = A;
			int initC = C;

			nc += na;
			na = 0;
			if (nc > initC) {
				initC = nc - initC;
				na = initC;
			}
			
			if (!visit[na][nb][nc]) {
				visit[na][nb][nc] = true;
				Q.push({ na,nb,nc });
			}

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

			if (!visit[na][nb][nc]) {
				visit[na][nb][nc] = true;
				Q.push({ na,nb,nc });
			}
		}
	
		//bc에 옮길때,
		if (!(b == 0 && c == 0))
		{
			//b->c
			int na = a;
			int nb = b;
			int nc = c;
			int initB = B;
			int initC = C;


			nc += nb;
			nb = 0;
			if (nc > initC) {
				initC = nc - initC;
				nb = initC;
			}
			if (!visit[na][nb][nc]) {
				visit[na][nb][nc] = true;
				Q.push({ na,nb,nc });
			}

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
			if (!visit[na][nb][nc]) {
				visit[na][nb][nc] = true;
				Q.push({ na,nb,nc });
			}
		}
		
		//ab에 옮길때,
		if (!(b == 0 && a == 0))
		{
			//a->b
			int na = a;
			int nb = b;
			int nc = c;
			int initA = A;
			int initB = B;

			nb += na;
			na = 0;
			if (nb > initB) {
				initB = nb - initB;
				na = initB;
			}
			
			if (!visit[na][nb][nc]) {
				visit[na][nb][nc] = true;
				Q.push({ na,nb,nc });
			}

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

			if (!visit[na][nb][nc]) {
				visit[na][nb][nc] = true;
				Q.push({ na,nb,nc });
			}
		}
		
	}

}
