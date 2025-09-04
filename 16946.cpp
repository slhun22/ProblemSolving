#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int field[1000][1000];
int res[1000][1000];
int area[1000005];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> q;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int N, M, i, j, k;
	string s;
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		cin >> s;
		for (j = 0; j < M; j++)
			field[i][j] = s[j] - '0';
	}

	int id = 2;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (field[i][j] == 0) {
				q.push({ i, j });
				field[i][j] = id;
				int cnt = 1;
				while (!q.empty()) {
					int r = q.front().first;
					int c = q.front().second;
					q.pop();

					for (k = 0; k < 4; k++) {
						int nr = r + dx[k];
						int nc = c + dy[k];
						if (nr < 0 || nr >= N || nc < 0 || nc >= M)
							continue;

						if (field[nr][nc] == 0) {
							field[nr][nc] = id;
							cnt++;
							q.push({ nr, nc });
						}
					}
				}
				area[id] = cnt;
				id++;
			}
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (field[i][j] == 1) {
				int used[4];
				int idx = 0;
				int sum = 1;
				for (k = 0; k < 4; k++) {
					int nr = i + dx[k];
					int nc = j + dy[k];
					if (nr < 0 || nr >= N || nc < 0 || nc >= M)
						continue;

					if (field[nr][nc] > 1 && find(used, used + idx, field[nr][nc]) == used + idx) {
						sum += area[field[nr][nc]];
						used[idx++] = field[nr][nc];
					}
				}
				res[i][j] = sum % 10;
			}
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++)
			cout << res[i][j];
		cout << "\n";
	}
}