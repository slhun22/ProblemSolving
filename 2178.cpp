#include<iostream>
#include<queue>

using namespace std;

struct Data {
	int r;
	int c;
	int cnt;
};

int field[100][100];
bool visited[100][100];
queue<Data> q;

void bfs(int r, int c, int cnt) {
	if (field[r][c] && !visited[r][c]) {
		q.push({ r, c, cnt + 1 });
		visited[r][c] = true;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int i, j, N, M;
	string s;
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		cin >> s;
		for (j = 0; j < M; j++)
			field[i][j] = s[j] - '0';
	}
	q.push({ 0, 0, 1 });
	visited[0][0] = true;
	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		int cnt = q.front().cnt;
		q.pop();
		if (r == N - 1 && c == M - 1) {
			cout << cnt;
			break;
		}
		if (r - 1 >= 0) bfs(r - 1, c, cnt);
		if (r + 1 < N) bfs(r + 1, c, cnt);
		if (c - 1 >= 0) bfs(r, c - 1, cnt);
		if (c + 1 < M) bfs(r, c + 1, cnt);
	}
}