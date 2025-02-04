#include <iostream>

using namespace std;

struct Matrix
{
	int r;
	int c;
};

int dp[500][500] = { -1, };
Matrix m[500];

int Min(int a, int b)//M[a, b] = min(M[a, k] + M[k + 1, b] + C[a - 1] x C[k] x C[b]) a <= k < b
{
	int i, min = 2147483647, value;
	for (i = a; i < b; i++)
	{
		int firstIdx;
		value = dp[a][i] + dp[i + 1][b] + m[a].r * m[i].c * m[b].c;
			
		if (value < min)
			min = value;
	}
	return min;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int i, j, N, r, c;
	cin >> N;

	for (i = 0; i < N; i++)
	{
		cin >> r >> c;
		m[i].r = r;
		m[i].c = c;
		dp[i][i] = 0;
	}

	for (i = 1; i < N; i++)
		for (j = 0; j < N - i; j++)
			dp[j][j + i] = Min(j, j + i);

	//cout << dp[0][N - 1];
}