#include<iostream>
using namespace std;

int board[128][128];
int cnt0 = 0, cnt1 = 0;

void split(int sr, int sc, int size) {
	int i, j, first = board[sr][sc];
	bool same = true;
	for (i = sr; i < sr + size; i++)
		for (j = sc; j < sc + size; j++)
			if (board[i][j] != first)
				same = false;
	if (!same) {
		int ssize = size / 2;
		split(sr, sc, ssize);
		split(sr + ssize, sc, ssize);
		split(sr, sc + ssize, ssize);
		split(sr + ssize, sc + ssize, ssize);
	}
	else {
		if (first)
			cnt1++;
		else
			cnt0++;
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int N,i,j;
	cin >> N;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	split(0, 0, N);
	cout << cnt0 << "\n" << cnt1;
}