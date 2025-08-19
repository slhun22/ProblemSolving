#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

struct CCTV {
	int r;
	int c;
	int n;
};

int N, M, mincnt = 65;
int field[8][8];
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
vector<int> type[6] = { {0}, { 0,1,2,3 }, {0,1}, {0,1,2,3}, {0,1,2,3}, {1} };
vector<CCTV> cctv;

void one(int r, int c, int idx) { //0 1 2 3
	int nr = r + dir[idx][0];
	int nc = c + dir[idx][1];

	if (nr < 0 || nr >= N || nc < 0 || nc >= M)
		return;

	if (field[nr][nc] != 6) {
		if (field[nr][nc] == 0)
			field[nr][nc] = -1;
		one(nr, nc, idx);
	}
}

void two(int r, int c, int type) { //0 1
	one(r, c, type);
	one(r, c, type + 2);
}

void three(int r, int c, int type) { //0 1 2 3
	one(r, c, type);
	one(r, c, (type + 1) % 4);
}

void four(int r, int c, int type) { //0 1 2 3
	for (int i = 0; i < 3; i++)
		one(r, c, (type + i) % 4);
}

void five(int r, int c) {
	for (int i = 0; i < 4; i++)
		one(r, c, i);
}

int sagak() {
	int cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (field[i][j] == 0) cnt++;
	return cnt;
}

void func(int idx) {
	if (idx == cctv.size()) {
		int cnt = sagak();
		if (cnt < mincnt)
			mincnt = cnt;
		return;
	}

	int r = cctv[idx].r;
	int c = cctv[idx].c;
	int n = cctv[idx].n;		
	int copy[8][8];
	memcpy(copy, field, sizeof(field));
	for (int i = 0; i < type[n].size(); i++) {
		if (n == 1) one(r, c, i);
		else if (n == 2) two(r, c, i);
		else if (n == 3) three(r, c, i);
		else if (n == 4) four(r, c, i);
		else if (n == 5) five(r, c);

		func(idx + 1);
		memcpy(field, copy, sizeof(copy));
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> M;
	int i, j;
	for (i = 0; i < N; i++) {
		for(j = 0; j < M; j++) {
			cin >> field[i][j];
			if (field[i][j] > 0 && field[i][j] < 6)
				cctv.push_back({ i, j, field[i][j] });
		}
	}

	func(0);
	cout << mincnt;
}