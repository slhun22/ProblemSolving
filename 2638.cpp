#include <iostream>
#include <queue>

using namespace std;

int N, M;
int board[100][100];
bool visited[100][100];
queue<pair<int, int>> q;

bool NoCheese() {
	int i, j, sum = 0;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			if (board[i][j])
				return false;
	return true;
}

int main() {
	int i, j, time = 0;
	
	cin >> N >> M;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			cin >> board[i][j];

	while (!NoCheese()) {
		for (i = 0; i < N; i++)
			for (j = 0; j < M; j++)
				visited[i][j] = false;

		q.push({ 0, 0 });

		while (!q.empty()) {
			pair<int, int> target = q.front();
			q.pop();
			int i = target.first;
			int j = target.second;

			if (visited[i][j] || board[i][j])
				continue;

			if (i == 0 || i == N - 1 || j == 0 || j == M - 1 || visited[i - 1][j] || visited[i + 1][j] || visited[i][j - 1] || visited[i][j + 1])
				visited[i][j] = true;

			if (i > 0) q.push({ i - 1, j });
			if (i < N - 1) q.push({ i + 1, j });
			if (j > 0) q.push({ i, j - 1 });
			if (j < M - 1) q.push({ i, j + 1 });
		}

		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				if (board[i][j] == 1) {
					int cnt = 0;
					if (visited[i - 1][j]) cnt++;
					if (visited[i + 1][j]) cnt++;
					if (visited[i][j - 1]) cnt++;
					if (visited[i][j + 1]) cnt++;

					if (cnt > 1) board[i][j] = 0;
				}
			}
		}
		time++;
	}

	cout << time;
}