#include <iostream>

using namespace std;

int N;
int cnt = 0;
int col[14] = { 0, };
int diag1[27] = { 0, };
int diag2[27] = { 0, };

void put(int r) {
	for (int c = 0; c < N; c++) {
		if (!col[c] && !diag1[r + c] && !diag2[r - c + N - 1]) {
			if (r == N - 1)
				cnt++;
			else {
				col[c] = diag1[r + c] = diag2[r - c + N - 1] = 1;
				put(r + 1);
				col[c] = diag1[r + c] = diag2[r - c + N - 1] = 0;
			}		
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> N;
	put(0);
	cout << cnt;
}