#include<iostream>
using namespace std;

int field[100][100];
char m[10001];
int hx = 0, hy = 0, ex = -1, ey = -1; //머리, 끝
int dx[4] = { 0, -1, 0, 1 }; //오 위 왼 아
int dy[4] = { 1, 0, -1, 0 };
int dir = 0;
int idx = 1;
int N;

bool OOB(int x, int y) {
	return x < 0 || x >= N || y < 0 || y >= N;
}

void rotate(char cmd) {
	if (cmd == 'L')
		dir = (dir + 1) % 4;
	else if (cmd == 'D') {
		dir--;
		if (dir < 0)
			dir += 4;
	}
}

bool snake() {
	hx += dx[dir];
	hy += dy[dir];
	if (OOB(hx, hy))
		return false;
	if (field[hx][hy] > 0)
		return false;

	if (field[hx][hy] == -1) {
		field[hx][hy] = ++idx;
		if (ex == -1) {
			ex = hx - dx[dir];
			ey = hy - dy[dir];
		}
	}
	else { //0
		field[hx][hy] = ++idx;
		if (ex != -1) {
			for (int i = 0; i < 4; i++) {
				if (OOB(ex + dx[i], ey + dy[i]))
					continue;

				if (field[ex + dx[i]][ey + dy[i]] == field[ex][ey] + 1) {
					field[ex][ey] = 0;
					ex = ex + dx[i];
					ey = ey + dy[i];
					break;
				}
			}
		}
		else {
			field[hx - dx[dir]][hy - dy[dir]] = 0;
		}
	}
	return true;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int K, L, a, b, i;
	char c;

	cin >> N >> K;
	for (i = 0; i < K; i++) {
		cin >> a >> b;
		field[a - 1][b - 1] = -1;
	}

	cin >> L;
	for (i = 0; i < L; i++) {
		cin >> a >> c;
		m[a] = c;
	}

	int cnt = 0;
	field[hx][hy] = idx;
	while (cnt < 10000) {
		cnt++;
		if (!snake()) {
			cout << cnt;
			break;
		}
		rotate(m[cnt]);
	}
}