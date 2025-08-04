#include<iostream>
#include<bitset>
using namespace std;

int field[10][10];
bitset<19> chk[1 << 19];
int n, ans;

void func(int diag, int visit, int cnt) {
	if (diag >= n * 2 - 1) {
		if (ans < cnt)
			ans = cnt;
		return;
	}

	if (!chk[visit].test(diag)) {
		chk[visit].set(diag);
		int blockcnt = (diag >= n) ? n * 2 - (diag + 1) : diag + 1;
		for (int i = 0; i < blockcnt; i++) {
			int r = min(n - 1, diag) - i;
			int c = diag - r;
			int anti_diag = r - c + n - 1;
			int bit = 1 << anti_diag;
			if (field[r][c] && !(bit & visit))
				func(diag + 2, bit | visit, cnt + 1);
		}
		func(diag + 2, visit, cnt);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int i, j;
	cin >> n;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			cin >> field[i][j];

	func(0, 0, 0);
	int first = ans;
	ans = 0;
	func(1, 0, 0);
	cout << first + ans;
}