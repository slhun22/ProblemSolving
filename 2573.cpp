#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int field[300][300];
bool visited[300][300];
int N, M;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void melt() {
	vector<pair<int, int>> melted;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (field[i][j]) {
				for (int k = 0; k < 4; k++) {
					int nr = i + dx[k];
					int nc = j + dy[k];
					if (nr < 0 || nr >= N || nc < 0 || nc >= M)
						continue;
					if (field[nr][nc] == 0) {
						field[i][j]--;
						if (field[i][j] == 0) {
							field[i][j]++;
							melted.push_back({ i, j });
							break;
						}
					}
				}
			}
		}
	}

	for (auto& pos : melted)
		field[pos.first][pos.second] = 0;
}

int checkcnt() {
	memset(visited, 0, sizeof(visited));
	queue<pair<int, int>> q;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (field[i][j] && !visited[i][j]) {
				q.push({ i, j });
				while (!q.empty()) {
					int r = q.front().first;
					int c = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nr = r + dx[k];
						int nc = c + dy[k];
						if (nr < 0 || nr >= N || nc < 0 || nc >= M)
							continue;
						if (field[nr][nc] && !visited[nr][nc]) {
							visited[nr][nc] = true;
							q.push({ nr, nc });
						}
					}
				}
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int i, j;
	cin >> N >> M;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			cin >> field[i][j];

	int t = 0;
	while (true) {
		melt();
		t++;
		int cnt = checkcnt();
		if (cnt > 1) {
			cout << t;
			return 0;
		}
		if (cnt == 0) {
			cout << 0;
			return 0;
		}
	}
}