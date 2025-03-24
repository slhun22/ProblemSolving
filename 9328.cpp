#include<iostream>
#include<vector>
using namespace std;

char field[100][100];
bool visited[100][100];
vector<pair<int, int>> doorpos[26];
vector<pair<int, int>> visitedDoorpos[26];
vector<pair<int, int>> startpos;

int h, w, maxcnt, cnt;

void dfs(int, int);

void diffuse(int i, int j) {
	if (field[i][j] == '*' || maxcnt <= cnt || visited[i][j])
		return;
	if ('A' <= field[i][j] && field[i][j] <= 'Z') {
		visitedDoorpos[field[i][j] - 'A'].push_back({ i, j });
		return;
	}

	if (field[i][j] == '$')
		cnt++;
	else if ('a' <= field[i][j] && field[i][j] <= 'z') {
		for (auto pos : doorpos[field[i][j] - 'a'])
			field[pos.first][pos.second] = '.';
		for (auto pos : visitedDoorpos[field[i][j] - 'a'])
			dfs(pos.first, pos.second);
	}
	dfs(i, j);
}

void dfs(int i, int j) {
	if (!visited[i][j]) {
		visited[i][j] = true;
		if (i + 1 < h)
			diffuse(i + 1, j);
		if (0 <= i - 1)
			diffuse(i - 1, j);
		if (j + 1 < w)
			diffuse(i, j + 1);
		if (0 <= j - 1)
			diffuse(i, j - 1);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int T, i, j;
	string keys;
	cin >> T;
	while (T-- > 0) {
		vector<pair<int, int>>().swap(startpos);
		for (i = 0; i < 26; i++) {
			vector<pair<int, int>>().swap(doorpos[i]);
			vector<pair<int, int>>().swap(visitedDoorpos[i]);
		}
		maxcnt = 0;
		cnt = 0;
		cin >> h >> w;
		for (i = 0; i < h; i++) {
			for (j = 0; j < w; j++) {
				visited[i][j] = false;
				cin >> field[i][j];
				if ('A' <= field[i][j] && field[i][j] <= 'Z')
					doorpos[field[i][j] - 'A'].push_back({ i, j });
				else if (field[i][j] == '$')
					maxcnt++;
			}
		}
		cin >> keys;
		if (keys != "0") {
			for (i = 0; i < keys.length(); i++) {
				if (!doorpos[keys[i] - 'a'].empty())
					for (auto pos : doorpos[keys[i] - 'a'])
						field[pos.first][pos.second] = '.';
			}
		}
		for (i = 0; i < h; i++) {
			for (j = 0; j < w; j++) {
				char v = field[i][j];
				if (v != '*' && (v < 'A' || 'Z' < v) && (i == 0 || i == h - 1 || j == 0 || j == w - 1)) {
					if ('a' <= v && v <= 'z') {
						if (!doorpos[v - 'a'].empty())
							for (auto pos : doorpos[v - 'a'])
								field[pos.first][pos.second] = '.';
					}
					else if (v == '$')
						cnt++;
				}
			}
		}
		for (i = 0; i < h; i++) {
			for (j = 0; j < w; j++) {
				char v = field[i][j];
				if (v != '*' && (i == 0 || i == h - 1 || j == 0 || j == w - 1)) {
					if ('A' <= v && v <= 'Z')
						visitedDoorpos[v - 'A'].push_back({ i, j });
					else
						startpos.push_back({ i, j });
				}
			}
		}
		for (auto s : startpos)
			dfs(s.first, s.second);			

		cout << cnt << "\n";
	}
}