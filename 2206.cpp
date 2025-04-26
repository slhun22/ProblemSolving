#include<iostream>
#include<queue>

using namespace std;

struct History {
	pair<int, int> pos;
	bool isWallBreaked;
	int cnt;
};

int board[1000][1000];
bool visited[1000][1000][2];
queue<History> q;

void diffuse(int i, int j, bool isWallBreaked, int cnt) {
	if (board[i][j] == 0) { //0
		if (!visited[i][j][isWallBreaked]) {
			q.push({ {i, j}, isWallBreaked, cnt + 1 });
			visited[i][j][isWallBreaked] = true;
		}
	}
	else if (!isWallBreaked) { //1
		if (!visited[i][j][0]) {
			q.push({ {i, j}, true, cnt + 1 });
			visited[i][j][0] = true;
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int N, M, i, j;
	string s;
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		cin >> s;
		for (j = 0; j < s.length(); j++) {
			board[i][j] = s[j] - '0';
		}
	}
	q.push({ {0, 0}, false, 1 });

	while (!q.empty()) {
		auto pos = q.front().pos;
		int i = pos.first;
		int j = pos.second;
		bool isWallBreaked = q.front().isWallBreaked;
		int cnt = q.front().cnt;

		if (i == N - 1 && j == M - 1) {
			cout << cnt;
			return 0;
		}

		q.pop();
		if (i - 1 >= 0)
			diffuse(i - 1, j, isWallBreaked, cnt);
		if (i + 1 < N)
			diffuse(i + 1, j, isWallBreaked, cnt);
		if (j - 1 >= 0)
			diffuse(i, j - 1, isWallBreaked, cnt);
		if (j + 1 < M)
			diffuse(i, j + 1, isWallBreaked, cnt);
	}

	cout << -1;
}