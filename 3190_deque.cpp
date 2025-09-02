#include<iostream>
#include<deque>
using namespace std;

int field[100][100];
char m[10001];
int dx[4] = {0, 1, 0, -1}; //¿À ¾Æ ¿Þ À§
int dy[4] = { 1, 0, -1 , 0 };
deque<pair<int, int>> dq;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int N, K, L, a, b, i;
	char c;

	cin >> N >> K;
	for (i = 0; i < K; i++) {
		cin >> a >> b;
		field[a - 1][b - 1] = 1;
	}

	cin >> L;
	for (i = 0; i < L; i++) {
		cin >> a >> c;
		m[a] = c;
	}

	dq.push_back({ 0, 0 });

	int cnt = 0;
	int dir = 0;
	while (cnt < N * N) {
		cnt++;
		auto head = dq.front();
		int nr = head.first + dx[dir];
		int nc = head.second + dy[dir];

		if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
			cout << cnt;
			return 0;
		}
		for (auto [r, c] : dq) {
			if (nr == r && nc == c) {
				cout << cnt;
				return 0;
			}
		}

		dq.push_front({ nr, nc });
		if (field[nr][nc])
			field[nr][nc] = 0;
		else
			dq.pop_back();

		if (m[cnt] == 'L')
			dir = (dir + 3) % 4;
		else if (m[cnt] == 'D')
			dir = (dir + 1) % 4;
	}
}