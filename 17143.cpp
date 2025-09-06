#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int R, C;

enum Dir {
	LEFT, DOWN, RIGHT, UP
};

int dconvert[5] = {0, 3, 1, 2, 0 };

struct shk {
	int id;
	int r;
	int c;
	int speed;
	int dir;
	int size;

	void flip() {
		dir = (dir + 2) % 4;
	}

	void move() {
		bool isFlip = false;
		if (dir == LEFT) {
			int remain = speed % (2 * (C - 1));
			if (c - remain < 0) {
				remain -= c;
				c = 0;
				isFlip ^= 1;
				if (remain > C - 1) {
					remain -= C - 1;
					c = C - 1;
					isFlip ^= 1;

					c -= remain;
				}
				else {
					c += remain;
				}
			}
			else {
				c -= remain;
			}
		}
		else if (dir == RIGHT) {
			int remain = speed % (2 * (C - 1));
			if (c + remain > C - 1) {
				remain -= C - 1 - c;
				c = C - 1;
				isFlip ^= 1;
				if (remain > C - 1) {
					remain -= C - 1;
					c = 0;
					isFlip ^= 1;

					c += remain;
				}
				else {
					c -= remain;
				}
			}
			else {
				c += remain;
			}
		}
		else if (dir == DOWN) {
			int remain = speed % (2 * (R - 1));
			if (r + remain > R - 1) {
				remain -= R - 1 - r;
				r = R - 1;
				isFlip ^= 1;
				if (remain > R - 1) {
					remain -= R - 1;
					r = 0;
					isFlip ^= 1;

					r += remain;
				}
				else {
					r -= remain;
				}
			}
			else {
				r += remain;
			}
		}
		else if (dir == UP) {
			int remain = speed % (2 * (R - 1));
			if (r - remain < 0) {
				remain -= r;
				r = 0;
				isFlip ^= 1;
				if (remain > R - 1) {
					remain -= R - 1;
					r = R - 1;
					isFlip ^= 1;

					r -= remain;
				}
				else {
					r += remain;
				}
			}
			else {
				r -= remain;
			}
		}

		if (isFlip)
			flip();
	}

	bool operator>(const shk& other) const {
		return r > other.r;
	}
};

int field[100][100];
vector<shk> sv;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int M, i, r, c, s, d, z;
	memset(field, -1, sizeof(field));
	cin >> R >> C >> M;

	for (i = 0; i < M; i++) {
		cin >> r >> c >> s >> d >> z;
		sv.push_back({ i, r - 1, c - 1, s, dconvert[d], z });
		field[r - 1][c - 1] = i;
	}

	int pos = 0;
	int sum = 0;
	while (pos < C) {
		for (i = 0; i < R; i++) {
			if (field[i][pos] != -1) {
				sum += sv[field[i][pos]].size;
				sv[field[i][pos]].id = -1;
				break;
			}
		}

		if (++pos == C)
			break;

		for (auto& s : sv)
			if (s.id != -1)
				s.move();

		memset(field, -1, sizeof(field));
		for (auto& s : sv) {
			if (s.id == -1)
				continue;

			int val = field[s.r][s.c];
			if (val != -1) {
				if (sv[val].size < s.size) {
					sv[val].id = -1;
					field[s.r][s.c] = s.id;
				}
				else
					s.id = -1;
			}
			else
				field[s.r][s.c] = s.id;
		}
	}

	cout << sum;
}