#include<iostream>
#include<stack>
using namespace std;

int N, K;
bool isFinished = false;
long long ans = -1;
bool visited[51][51][1250];

void dfs(int cnt, int bcnt, int paircnt, long long st) {
	if (isFinished)
		return;
	if (paircnt > K)
		return;
	if (visited[cnt][bcnt][paircnt])
		return;
	if (cnt == N) {
		if (paircnt == K) {
			isFinished = true;
			ans = st;
		}
		return;
	}

	visited[cnt][bcnt][paircnt] = true;
	dfs(cnt + 1, bcnt, paircnt + bcnt, st | (1LL << cnt));
	dfs(cnt + 1, bcnt + 1, paircnt, st);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> K;
	dfs(0, 0, 0, 0);

	if (ans == -1) {
		cout << -1;
		return 0;
	}

	stack<char> st;

	for (int i = 0; i < N; i++) {
		long long b = ans & (1LL << i);
		st.push(b ? 'A' : 'B');
	}

	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
}