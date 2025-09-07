#include<iostream>
using namespace std;

int field[20][20];
int dice[6]; //아래 앞 좌 위 뒤 우
int down = 0, forwd = 1, lft = 2;
int N, M, r, c;

void move(int dir) {
	int t;
	if (dir == 1 && c + 1 >= M)
		return;
	if (dir == 2 && c - 1 < 0)
		return;
	if (dir == 3 && r - 1 < 0)
		return;
	if (dir == 4 && r + 1 >= N)
		return;
		
	if (dir == 1) { //동
		c++;
		t = down;
		down = (lft + 3) % 6;
		lft = t;
	}
	else if (dir == 2) { //서
		c--;
		t = lft;
		lft = (down + 3) % 6;
		down = t;
	}
	else if (dir == 3) { //북
		r--;
		t = down;
		down = (forwd + 3) % 6;
		forwd = t;
	}
	else if (dir == 4) { //남
		r++;
		t = forwd;
		forwd = (down + 3) % 6;
		down = t;
	}

	if (field[r][c]) {
		dice[down] = field[r][c];
		field[r][c] = 0;
	}
	else
		field[r][c] = dice[down];

	cout << dice[(down + 3) % 6] << "\n";
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int K, i, j;
	cin >> N >> M >> r >> c >> K;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			cin >> field[i][j];

	int dir;
	while (K-- > 0) {
		cin >> dir;
		move(dir);
	}
}