#include<iostream>
#include<queue>
using namespace std;

struct Dat {
	int cnt;
	int bx;
	int by;
	int rx;
	int ry;
	int beforeDir;
};

int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
vector<vector<char>> field(10, vector<char>(10));
bool visited[10][10][10][10];

int Move(int idx, int& x, int& y, bool& isGoal) {
	int cnt = 0;
	while (true) {
		x += dir[idx][0];
		y += dir[idx][1];
		cnt++;
		
		if (field[x][y] == 'O') {
			isGoal = true;
			break;
		}
		if (field[x][y] == '#') {
			x -= dir[idx][0];
			y -= dir[idx][1];
			break;
		}
	}

	return cnt;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	queue<Dat> q;
	int N, M, i, j, bx, by, rx, ry, mincnt = 20;

	cin >> N >> M;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++) {
			cin >> field[i][j];
			if (field[i][j] == 'B') {
				bx = i;
				by = j;
			}
			else if (field[i][j] == 'R') {
				rx = i;
				ry = j;
			}
		}

	q.push({ 1, bx, by, rx, ry, -1 });
	visited[bx][by][rx][ry] = true;

	while (!q.empty()) {
		const int cnt_q = q.front().cnt;
		const int bx_q = q.front().bx;
		const int by_q = q.front().by;
		const int rx_q = q.front().rx;
		const int ry_q = q.front().ry;
		const int beforeDir = q.front().beforeDir;
		q.pop();

		for (i = 0; i < 4; i++) {
			if (beforeDir == 0 && i == 2 || beforeDir == 1 && i == 3 || beforeDir == 2 && i == 0 || beforeDir == 3 && i == 1) continue;
			bool isBlueHole = false;
			bool isRedHole = false;
			int newBx = bx_q;
			int newBy = by_q;
			int newRx = rx_q;
			int newRy = ry_q;
			int distB = Move(i, newBx, newBy, isBlueHole);
			int distR = Move(i, newRx, newRy, isRedHole);

			if (!isBlueHole) {
				if (isRedHole) {
					if (mincnt > cnt_q)
						mincnt = cnt_q;
				}
				else {
					if (newBx == newRx && newBy == newRy) {
						if (distB > distR) {
							newBx -= dir[i][0];
							newBy -= dir[i][1];
						}
						else {
							newRx -= dir[i][0];
							newRy -= dir[i][1];
						}
					}

					if (!visited[newBx][newBy][newRx][newRy] && cnt_q < 10 && cnt_q < mincnt - 1) {
						visited[newBx][newBy][newRx][newRy] = true;
						q.push({ cnt_q + 1, newBx, newBy, newRx, newRy, i });
					}	
				}
			}
		}
	}

	cout << (mincnt == 20? -1 : mincnt);
}