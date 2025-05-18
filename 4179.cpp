#include<iostream>
#include<queue>

using namespace std;

struct Pos {
	bool isFire;
	int time;
	int r;
	int c;

	Pos(bool isF, int time, int r, int c) : isFire(isF), time(time), r(r), c(c) {}
};

int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
char field[1000][1000];
bool visited[1000][1000];
queue<Pos> q;
int R, C;

void Diffuse(bool isFire, int time, int i, int j) {
	if (field[i][j] != '#' && !visited[i][j] && i >= 0 && i < R && j >= 0 && j < C) {
		visited[i][j] = true;
		if (isFire)
			field[i][j] = 'F';
		else
			field[i][j] = 'J';

		q.emplace(isFire, time + 1, i, j);
	}
}

bool IsEdge(int i, int j) {
	return i == 0 || i == R - 1 || j == 0 || j == C - 1;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int i, j;
	pair<int, int> jpos;
	cin >> R >> C;
	for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) {
			cin >> field[i][j];
			if (field[i][j] == 'F') {
				q.emplace(true, 1, i, j);
				visited[i][j] = true;
			}
			else if (field[i][j] == 'J')
				jpos = { i, j };
		}
	}
	q.emplace(false, 1, jpos.first, jpos.second);
	visited[jpos.first][jpos.second] = true;

	while (!q.empty()) {
		bool isFire = q.front().isFire;
		int time = q.front().time;
		int r = q.front().r;
		int c = q.front().c;
		q.pop();

		if (!isFire && IsEdge(r, c)) {
			cout << time;
			return 0;
		}

		for (i = 0; i < 4; i++)
			Diffuse(isFire, time, r + dir[i][0], c + dir[i][1]);
	}

	cout << "IMPOSSIBLE";
}