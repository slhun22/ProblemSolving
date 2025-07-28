#include<iostream>
#include<deque>
#include<vector>
#define LIMIT 5

using namespace std;

vector<vector<int>> field(20, vector<int>(20));
int N, maxnum = -1;
deque<int> dq;

enum Dir { UP, DOWN, LEFT, RIGHT};

void Move(Dir dir) {
	int r, c;
	bool isMerged = false;
	if (dir == UP) {
		for (c = 0; c < N; c++) {
			for (r = 0; r < N; r++) {
				if (field[r][c] != 0) {
					if (!dq.empty() && dq.back() == field[r][c] && !isMerged) {
						dq.pop_back();
						dq.push_back(field[r][c] * 2);
						isMerged = true;
					}
					else {
						dq.push_back(field[r][c]);
						isMerged = false;
					}
					field[r][c] = 0;
				}
			}

			int length = dq.size();
			for (r = 0; r < length; r++) {
				field[r][c] = dq.front();
				dq.pop_front();
			}
		}
	}
	else if (dir == DOWN) {
		for (c = 0; c < N; c++) {
			for (r = N - 1; r >= 0; r--) {
				if (field[r][c] != 0) {
					if (!dq.empty() && dq.back() == field[r][c] && !isMerged) {
						dq.pop_back();
						dq.push_back(field[r][c] * 2);
						isMerged = true;
					}
					else {
						dq.push_back(field[r][c]);
						isMerged = false;
					}
					field[r][c] = 0;
				}
			}

			int length = dq.size();
			for (r = 0; r < length; r++) {
				field[N - r - 1][c] = dq.front();
				dq.pop_front();
			}
		}
	}
	else if (dir == LEFT) {
		for (r = 0; r < N; r++) {
			for (c = 0; c < N; c++) {
				if (field[r][c] != 0) {
					if (!dq.empty() && dq.back() == field[r][c] && !isMerged) {
						dq.pop_back();
						dq.push_back(field[r][c] * 2);
						isMerged = true;
					}
					else {
						dq.push_back(field[r][c]);
						isMerged = false;
					}
					field[r][c] = 0;
				}
			}

			int length = dq.size();
			for (c = 0; c < length; c++) {
				field[r][c] = dq.front();
				dq.pop_front();
			}
		}
	}
	else if (dir == RIGHT) {
		for (r = 0; r < N; r++) {
			for (c = N - 1; c >= 0; c--) {
				if (field[r][c] != 0) {
					if (!dq.empty() && dq.back() == field[r][c] && !isMerged) {
						dq.pop_back();
						dq.push_back(field[r][c] * 2);
						isMerged = true;
					}
					else {
						dq.push_back(field[r][c]);
						isMerged = false;
					}
					field[r][c] = 0;
				}
			}

			int length = dq.size();
			for (c = 0; c < length; c++) {
				field[r][N - c - 1] = dq.front();
				dq.pop_front();
			}
		}
	}
}

void BackTracking(int cnt) {
	int i, j;
	if (cnt == LIMIT) {
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (field[i][j] > maxnum)
					maxnum = field[i][j];
			}
		}
	}
	else {
		for (i = 0; i < 4; i++) {
			auto fieldCopy = field;
			Move((Dir)i);
			BackTracking(cnt + 1);
			field = fieldCopy;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int i, j;
	cin >> N;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			cin >> field[i][j];

	BackTracking(0);
	cout << maxnum;
}