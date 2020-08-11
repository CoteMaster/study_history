#include<cstdio>
#include<cstdlib>
#include<queue>
#include<iostream>

using namespace std;

int R, C;
char map[55][55];
int wx, wy, curx, cury, rx, ry;
int water[55][55] = { -1, };
int visit[55][55] = { -1, };
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

queue<pair<int, int>>wQ,Q;

void w_BFS()
{
	
	while (!wQ.empty())
	{
		int cwx = wQ.front().first;
		int cwy = wQ.front().second;
		wQ.pop();

		for(int i = 0; i < 4; i++)
		{
			int nwx = cwx + dx[i];
			int nwy = cwy + dy[i];

			if (nwx < 0 || nwx >= C || nwy < 0 || nwy >= R)continue;
			if (map[nwx][nwy] == '.' && water[nwx][nwy] == -1)
			{
				water[nwx][nwy] = water[cwx][cwy] + 1;
				wQ.push({ nwx,nwy });
			}
		}
	}
}

void BFS()
{
	
	while (!Q.empty())
	{
		int cx = Q.front().first;
		int cy = Q.front().second;
		
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || nx >= C || ny < 0 || ny >= R)continue;

			
			if (map[nx][ny] == '.' && visit[nx][ny] == -1 && (visit[cx][cy] + 1 < water[nx][ny] || water[nx][ny] == -1))
			{

				visit[nx][ny] = visit[cx][cy] + 1;
				Q.push({ nx,ny });
				
			}
			
		}
	}
}

int main()
{
	cin >> C >> R;
	for (int i = 0; i < C; i++)
	{
		for (int j = 0; j < R; j++)
			cin >> map[i][j];
	}

	for (int i = 0; i < C; i++)
	{
		for (int j = 0; j < R; j++)
		{
			water[i][j] = -1;
			visit[i][j] = -1;
			if (map[i][j] == '*')
			{
				wx = i;
				wy = j;
				wQ.push({ wx,wy });
				water[wx][wy] = 0;
			}
			if (map[i][j] == 'S')
			{
				curx = i;
				cury = j;
				map[i][j] = '.';
				Q.push({ curx,cury });
				visit[curx][cury] = 0;
			}
			if (map[i][j] == 'D')
			{
				rx = i;
				ry = j;
				map[i][j] = '.';
				water[i][j] = 3000;
			}

		}
	}

	w_BFS();

	BFS();
	
	if (visit[rx][ry] != -1)
		printf("%d", visit[rx][ry]);
	else
		printf("KAKTUS");

	//system("pause");
	return 0;
}
