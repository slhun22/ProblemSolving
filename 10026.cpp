#include<iostream>
using namespace std;
int N;
char field[100][100];
bool visited[100][100];

void dfs(int r, int c) {
	visited[r][c] = true;
	char color = field[r][c];
	if (r - 1 >= 0 && field[r - 1][c] == color && !visited[r - 1][c])
		dfs(r - 1, c);
	if (r + 1 < N && field[r + 1][c] == color && !visited[r + 1][c])
		dfs(r + 1, c);
	if (c + 1 < N && field[r][c + 1] == color && !visited[r][c + 1])
		dfs(r, c + 1);
	if (c - 1 >= 0 && field[r][c - 1] == color && !visited[r][c - 1])
		dfs(r, c - 1);
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> N;
	int i, j, cnt = 0;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			cin >> field[i][j];
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (!visited[i][j]) {
				cnt++;
				dfs(i, j);
			}
		}
	}
	cout << cnt << " ";
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (field[i][j] == 'G')
				field[i][j] = 'R';
			visited[i][j] = false;
		}
	}
	cnt = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (!visited[i][j]) {
				cnt++;
				dfs(i, j);
			}
		}
	}
	cout << cnt;
}