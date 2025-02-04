#include <iostream>
#include <vector>
#include <queue>

//BFS와 ref 연산자의 중요성
using namespace std;

int N, sharkSize = 2;

struct Pos
{
	int r;
	int c;

	Pos operator+ (Pos& a)
	{
		return { r + a.r, c + a.c };
	}
};

Pos unitPos[4] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };//up, down, left, right
Pos sharkPos;

void Clear(int dp[][20], int visited[][20])
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			dp[i][j] = 9999;
			visited[i][j] = 0;
		}		

	dp[sharkPos.r][sharkPos.c] = 0;
}

bool InFieldCheck(Pos x)
{
	return x.r >= 0 && x.r < N && x.c >= 0 && x.c < N;
}

void BFS(int dp[][20], int field[][20], int visited[][20], queue<Pos>& q)
{
	while (!q.empty())
	{
		Pos x = q.front();
		q.pop();
		if (!visited[x.r][x.c])
		{
			visited[x.r][x.c] = 1;
			int cost = dp[x.r][x.c];
			for (int i = 0; i < 4; i++)
			{
				if (InFieldCheck(x + unitPos[i]))
				{
					if (field[(x + unitPos[i]).r][(x + unitPos[i]).c] > sharkSize && field[(x + unitPos[i]).r][(x + unitPos[i]).c] != 9)
						continue;

					else if (dp[(x + unitPos[i]).r][(x + unitPos[i]).c] > cost + 1)
						dp[(x + unitPos[i]).r][(x + unitPos[i]).c] = cost + 1;	

					q.push(x + unitPos[i]);
				}
			}
		}	
	}
}

void Eat(Pos target, int field[][20], int dp[][20], int& time, int& eatCnt)
{
	time += dp[target.r][target.c];
	eatCnt++;
	field[sharkPos.r][sharkPos.c] = 0;
	field[target.r][target.c] = 9;
	sharkPos = target;

	if (sharkSize == eatCnt)
	{
		sharkSize++;
		eatCnt = 0;
	}
}

int FindTarget(int field[][20], int dp[][20], int& time, int& eatCnt)
{
	vector<Pos> possibleTargets;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (field[i][j] > 0 && field[i][j] != 9 && field[i][j] < sharkSize)
					possibleTargets.push_back({ i , j });

	if (possibleTargets.empty())
	{
		return -1;
	}

	else
	{
		Pos target = possibleTargets[0];

		for (auto iter : possibleTargets)
		{
			if (dp[target.r][target.c] > dp[iter.r][iter.c])
				target = iter;

			else if (dp[target.r][target.c] == dp[iter.r][iter.c])
			{
				if (target.r > iter.r) target = iter;
				else if (target.r == iter.r)
				{
					if (target.c > iter.c) target = iter;
				}
			}
		}

		if (dp[target.r][target.c] >= 9999)
			return -1;

		Eat(target, field, dp, time, eatCnt);
		return 0;
	}	
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j, field[20][20], dp[20][20], time = 0, eatCnt = 0;
	int visited[20][20];
	queue<Pos> q;
	cin >> N;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
		{
			cin >> field[i][j];
			if (field[i][j] == 9)
				sharkPos = { i , j };
		}
	
	do
	{	
		Clear(dp, visited); 
		q.push(sharkPos);
		BFS(dp, field, visited, q);
	} while (FindTarget(field, dp, time, eatCnt) != -1);

	cout << time;
}