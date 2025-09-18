#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

struct rotdat {
	int x;
	bool ccw;
	int d;
};

int N, M, T;
int field[51][50];//원판 번호는 1-based, 방향은 0-based 꼭대기부터 시계방향으로
rotdat rotdats[51];

void rotate(int num, bool ccw, int d) {
	int i;
	int temp[50];
	if (ccw) {
		for (i = 0; i < M; i++)
			temp[(i - d + M) % M] = field[num][i];
		for (i = 0; i < M; i++)
			field[num][i] = temp[i];
	}
	else {
		for (i = 0; i < M; i++)
			temp[(i + d) % M] = field[num][i];
		for (i = 0; i < M; i++)
			field[num][i] = temp[i];
	}
}

void rotate_all(int t) {
	int x = rotdats[t].x;
	bool ccw = rotdats[t].ccw;
	int d = rotdats[t].d;
	for (int i = x; i <= N; i += x)
		rotate(i, ccw, d);
}

void adj_chk() {
	bool dead[51][50];
	int deadcnt = 0;
	memset(dead, 0, sizeof(dead));
	for (int i = 1; i <= N; i++) {
		int idx = i;
		for (int j = 0; j < M; j++) {
			int pos = j;
			int num = field[idx][pos];

			bool find = false;
			//동일 원판 좌우
			if (num > 0 && !dead[idx][(pos + 1) % M] && field[idx][(pos + 1) % M] == num) {
				find = true;
				dead[idx][(pos + 1) % M] = true;
				deadcnt++;
			}

			if (num > 0 && !dead[idx][(pos - 1 + M) % M] && field[idx][(pos - 1 + M) % M] == num) {
				find = true;
				dead[idx][(pos - 1 + M) % M] = true;
				deadcnt++;
			}

			//바로 위
			if (idx < N) {
				if (num > 0 && field[idx + 1][pos] == num) {
					if (!dead[idx + 1][pos]) {
						find = true;
						dead[idx + 1][pos] = true;
						deadcnt++;
					}
				}
			}

			//자기 자신 결산
			if (find) {
				if (!dead[idx][pos]) {
					dead[idx][pos] = true;
					deadcnt++;
				}
			}
		}
	}

	int i, j;
	if (deadcnt == 0) {
		int sum = 0;
		int cnt = 0;
		for (i = 1; i <= N; i++)
			for (j = 0; j < M; j++) {
				if (field[i][j] > 0) {
					sum += field[i][j];
					cnt++;
				}
			}

		if (cnt == 0)
			return;

		float avg = (float)sum / (float)cnt;

		for (i = 1; i <= N; i++)
			for (j = 0; j < M; j++) {
				if (field[i][j] == 0)
					continue;

				if (field[i][j] > avg)
					field[i][j]--;
				else if (field[i][j] < avg)
					field[i][j]++;
			}
	}
	else {
		for (i = 1; i <= N; i++)
			for (j = 0; j < M; j++)
				if (dead[i][j])
					field[i][j] = 0;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int i, j, x, ccw, d;
	cin >> N >> M >> T;

	for (i = 1; i <= N; i++)
		for (j = 0; j < M; j++)
			cin >> field[i][j];

	for (i = 1; i <= T; i++) {
		cin >> x >> ccw >> d;
		rotdats[i] = { x, (bool)ccw, d };
	}

	int t = 0;
	while (T-- > 0) {
		t++;
		rotate_all(t);
		adj_chk();
	}

	int ans = 0;
	for (i = 1; i <= N; i++)
		for (j = 0; j < M; j++)
			ans += field[i][j];
	cout << ans;
}