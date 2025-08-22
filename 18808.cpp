#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int field[40][40];
int st[10][10];
int N, M;

void rotate(int& R, int& C) {
	int offsetc = R - 1;
	int res[10][10] = { 0, };
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			res[j][-i + offsetc] = st[i][j];
	memcpy(st, res, sizeof(res));
	swap(R, C);
}

bool check(int sr, int sc, int R, int C) {
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (field[i + sr][j + sc] && st[i][j])
				return false;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (st[i][j])
				field[i + sr][j + sc] = 1;
	return true;
}

bool put(int R, int C) {
	for (int sr = 0; sr < N - R + 1; sr++)
		for (int sc = 0; sc < M - C + 1; sc++)
			if (check(sr, sc, R, C))
				return true;
	return false;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int K, R, C, i, j, k;
	cin >> N >> M >> K;
	while (K-->0) {
		cin >> R >> C;
		for (i = 0; i < R; i++)
			for (j = 0; j < C; j++)
				cin >> st[i][j];
		
		for (i = 0; i < 4; i++) {
			if (put(R, C))
				break;
			else
				rotate(R, C);
		}		
	}

	int ans = 0;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			if (field[i][j])
				ans++;

	cout << ans;
}