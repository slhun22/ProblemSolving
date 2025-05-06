#include <iostream>
#include <vector>

using namespace std;

int pointing[100001];
vector<int> flag(100001);
int cnt, n, idx;

void dfs(int start, int now) {
	if (flag[now]) {
		if (flag[now] == start) {
			cnt--;
			for (int i = pointing[now]; i != now; i = pointing[i])
				cnt--;
		}
	}
	else {
		flag[now] = start;
		dfs(start, pointing[now]);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int T, i;
	cin >> T;
	while (T-- > 0) {
		cin >> n;
		cnt = n;
		for (i = 1; i <= n; i++) {
			cin >> pointing[i];
			flag[i] = 0;
		}
		for (i = 1; i <= n; i++)
			dfs(i, i);
		cout << cnt << "\n";
	}
}