#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

struct tr {
	int r;
	int c;
	int age;
};

int N, M, K;
int field[10][10];
int A[10][10];
deque<int> tv[10][10];
int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };

void spring_summer() {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			int dead = 0;
			int length = tv[i][j].size();
			for (int k = 0; k < length; k++) {
				int age = tv[i][j].front();
				tv[i][j].pop_front();
				if (field[i][j] >= age) {
					field[i][j] -= age;
					tv[i][j].push_back(age + 1);
				}
				else
					dead += age / 2;
			}

			field[i][j] += dead;
		}
	}
}

void autumn() {
	int i, j, k;
	int cnt[10][10];
	memset(cnt, 0, sizeof(cnt));
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			for (auto age : tv[i][j]) {
				if (age % 5 == 0) {
					for (k = 0; k < 8; k++) {
						int nr = i + dx[k];
						int nc = j + dy[k];
						if (nr < 0 || nr >= N || nc < 0 || nc >= N)
							continue;

						cnt[nr][nc]++;
					}
				}
			}
		}
	}

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			for (k = 0; k < cnt[i][j]; k++)
				tv[i][j].push_front(1);
}

void winter() {
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			field[i][j] += A[i][j];
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> M >> K;
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) {
			field[i][j] = 5;
			cin >> A[i][j];
		}

	int r, c, age;

	for (i = 0; i < M; i++) {
		cin >> r >> c >> age;
		tv[r - 1][c - 1].push_back(age);
	}

	while (K-- > 0) {
		spring_summer();
		autumn();
		winter();
	}

	int cnt = 0;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			cnt += tv[i][j].size();

	cout << cnt;
}