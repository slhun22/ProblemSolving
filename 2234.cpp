#include<iostream>
#include<queue>
#include<set>
using namespace std;

int field[50][50];
bool blocked[50][50][4]; //¼­ ºÏ µ¿ ³²
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
vector<int> area;
queue<pair<int,int>> q;
set<pair<int, int>> s; //ÀÎÁ¢ Áö¿ª ½Ö

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int M, N, i, j, k, n;
	cin >> N >> M;
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			cin >> n;
			for (k = 0; k < 4; k++) {
				blocked[i][j][k] = n % 2;
				n /= 2;
			}
		}
	}
	area.push_back(0);
	int id = 1;
	int maxv = -1;
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			if (field[i][j] == 0) {
				field[i][j] = id;
				int cnt = 1;
				q.emplace(i, j);
				while (!q.empty()) {
					int r = q.front().first;
					int c = q.front().second;
					q.pop();

					for (k = 0; k < 4; k++) {
						int nr = r + dx[k];
						int nc = c + dy[k];

						if (nr < 0 || nr >= M || nc < 0 || nc >= N)
							continue;
						if (blocked[r][c][k] || blocked[nr][nc][(k + 2) % 4])
							continue;

						if (field[nr][nc] == 0) {
							field[nr][nc] = id;
							cnt++;
							q.emplace(nr, nc);
						}
					}
				}
				maxv = max(maxv, cnt);
				area.push_back(cnt);
				id++;
			}
		}
	}

	cout << area.size() - 1 << "\n";
	cout << maxv << "\n";

	for (i = 0; i < M; i++) { //horizontal
		for (j = 0; j < N - 1; j++) {
			int v1 = field[i][j];
			int v2 = field[i][j + 1];
			if (v1 < v2)
				s.emplace(v1, v2);
			else if (v1 > v2)
				s.emplace(v2, v1);
		}
	}

	for (i = 0; i < N; i++) { //vertical
		for (j = 0; j < M - 1; j++) {
			int v1 = field[j][i];
			int v2 = field[j + 1][i];
			if (v1 < v2)
				s.emplace(v1, v2);
			else if (v1 > v2)
				s.emplace(v2, v1);
		}
	}

	maxv = -1;
	for (auto& it : s)
		maxv = max(maxv, area[it.first] + area[it.second]);

	cout << maxv;
}