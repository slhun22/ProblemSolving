#include<iostream>
#include<deque>

using namespace std;

int field[100][100];
int N, L, ans = 0;

void func(bool horizontal) {
	for (int i = 0; i < N; i++) {
		deque<pair<int, bool>> dq;
		if (horizontal)
			dq.push_back({ field[i][0], false });
		else
			dq.push_back({ field[0][i], false });

		bool impossible = false;
		bool success = false;
		int cnt = 0;
		for (int j = 1; j < N; j++) {
			int val = horizontal ? field[i][j] : field[j][i];

			if (cnt > 0) {
				if (dq.back().first == val)
					cnt++;
				else
					impossible = true;

				if (cnt == L) {
					cnt = 0;
					success = true;
				}
			}
			else {
				if (dq.back().first == val - 1) {
					if (dq.size() == L) {
						for (auto it : dq) {
							if (it.first != dq.back().first || it.second) {
								impossible = true;
								break;
							}
						}
					}
					else
						impossible = true;
				}
				else if (dq.back().first == val + 1) {
					cnt++;

					if (cnt == L) {
						cnt = 0;
						success = true;
					}
				}
				else if (dq.back().first != val)
					impossible = true;
			}

			if (impossible)
				break;

			dq.push_back({ val, success });

			if (success)
				success = false;

			if (dq.size() > L)
				dq.pop_front();
		}

		if (cnt > 0 && cnt < L)
			impossible = true;

		if (!impossible)
			ans++;
	}	
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int i, j;
	cin >> N >> L;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			cin >> field[i][j];

	func(true);
	func(false);

	cout << ans;
}