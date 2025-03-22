#include<iostream>
#include<queue>
using namespace std;

int field[3100][3100];
queue<pair<int, int>> q;

void diffuse(int i, int j, int v) {
	if (!field[i][j]) {
		field[i][j] = v + 1;
		q.push({ i, j });
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int N, M, i, j, K, cnt = 0;
	string s;
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		cin >> s;
		for (j = 0; j < M; j++) {
			if (s[j] == 'o') {
				field[1525 + i][1525 + j] = 1;
				q.push({ 1525 + i, 1525 + j });
			}
		}
	}
	cin >> K;
	while (!q.empty()) {
		auto f = q.front();
		int i = f.first, j = f.second;
		int v = field[i][j];
		q.pop();
		cnt++;
		if (field[i][j] <= K) {
			diffuse(i - 1, j, v);
			diffuse(i + 1, j, v);
			diffuse(i, j - 1, v);
			diffuse(i, j + 1, v);
		}		
	}
	cout << cnt;
}