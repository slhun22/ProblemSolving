#include<iostream>
#include<cstring>
using namespace std;

int N, myIdx, ans = -1, pCnt;
int g[16];
int R[16][16];

int day(int dead) {
	int maxv = -1;
	int idx = 0;
	for (int i = 0; i < N; i++) {
		if (!(dead & (1 << i)) && maxv < g[i]) {
			maxv = g[i];
			idx = i;
		}
	}

	return idx;
}

void dfs(int ncnt, int dead, int victim) {
	if (ans == pCnt / 2)
		return;

	if (victim == myIdx) {
		if (ans < ncnt)
			ans = ncnt;
		return;
	}
	if (ncnt + 1 == pCnt / 2) {
		if (ans < ncnt + 1)
			ans = ncnt + 1;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!(dead & (1 << i)) && i != myIdx) {
			int copy[16];
			memcpy(copy, g, sizeof(g));

			for (int j = 0; j < N; j++)
				if (!(dead & (1 << j)))
					g[j] += R[i][j];

			int victim = day(dead | (1 << i));
			dfs(ncnt + 1, dead | (1 << i) | (1 << victim), victim);

			memcpy(g, copy, sizeof(g));
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int i, j;
	cin >> N;
	for (i = 0; i < N; i++)
		cin >> g[i];

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			cin >> R[i][j];

	cin >> myIdx;
	pCnt = N;
	int deadstate = 0;
	if (N % 2) {
		int victim = day(deadstate);
		if (victim == myIdx) {
			cout << 0;
			return 0;
		}
		pCnt--;
		deadstate |= (1 << victim);
	}

	dfs(0, deadstate, -1);
	cout << ans;
}