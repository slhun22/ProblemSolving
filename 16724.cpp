#include<iostream>

using namespace std;

char dir[1000][1000];
pair<int ,int> parent[1000][1000];
int cnt = 0;

pair<int, int> getDir(char dir, int i, int j) {
	switch (dir) {
	case 'U':
		return { i - 1, j };
	case 'D':
		return { i + 1, j };
	case 'L':
		return { i, j - 1 };
	case 'R':
		return { i , j + 1 };
	}
}

pair<int, int> findParent(pair<int, int> pos) {
	if (pos == parent[pos.first][pos.second])
		return pos;
	return parent[pos.first][pos.second] = findParent(parent[pos.first][pos.second]);
}

void dfs(pair<int , int> pos, pair<int, int> beforePos) { //union
	if (parent[pos.first][pos.second].first == -1) {
		if (beforePos.first == -1) {
			parent[pos.first][pos.second] = pos;
			cnt++;
		}
		else {
			parent[pos.first][pos.second] = findParent(beforePos);
		}
		dfs(getDir(dir[pos.first][pos.second], pos.first, pos.second), pos);
	}
	else if (findParent(beforePos) != findParent(parent[pos.first][pos.second])) {
		auto origin = findParent(parent[pos.first][pos.second]);
		parent[origin.first][origin.second] = findParent(beforePos);
		cnt--;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int i, j, M, N;
	cin >> M >> N;
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			cin >> dir[i][j];
			parent[i][j] = { -1, -1 };
		}
	}
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			if (parent[i][j].first == -1)
				dfs({ i, j }, { -1,-1 });
		}
	}
	cout << cnt;
}