#include<iostream>
#include<queue>

using namespace std;

struct Pos {
	int day;
	int x;
	int y;
	int z;
	Pos(int day, int x, int y, int z) : day(day), x(x), y(y), z(z) {}
};

int dir[6][3] = { {1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1} };
int field[100][100][100];
bool visited[100][100][100];
queue<Pos> q;
int N, M, H, leftcnt, lastday;

void diffuse(int day, int i, int j, int k) {
	if (i >= 0 && i < N && j >= 0 && j < M && k >= 0 && k < H && field[i][j][k] == 0 && !visited[i][j][k]) {
		visited[i][j][k] = true;
		field[i][j][k] = 1;
		leftcnt--;
		lastday = day + 1;
		q.emplace(day + 1, i, j, k);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int i,j,k;
	cin >> M >> N >> H;

	for (k = 0; k < H; k++) {
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				cin >> field[i][j][k];
				if (field[i][j][k] == 1)
					q.emplace(0, i, j, k);
				else if (field[i][j][k] == 0)
					leftcnt++;
			}
		}
	}

	while (!q.empty()) {
		int day = q.front().day;
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		q.pop();

		if (leftcnt == 0) {
			cout << lastday;
			return 0;
		}

		for (i = 0; i < 6; i++)
			diffuse(day, x + dir[i][0], y + dir[i][1], z + dir[i][2]);
	}

	cout << -1;
}