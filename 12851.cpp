#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

queue<int> q; //t-p
int dpt[100001];
int dpc[100001];
int K;

void update(int origin, int t, int pos) {
	if (pos < 0 || pos > 100000)
		return;

	if (dpt[pos] == -1) {
		dpt[pos] = t;
		dpc[pos] = dpc[origin];
		if (pos != K)
			q.push(pos);
	}
	else if (dpt[pos] == t)
		dpc[pos] += dpc[origin];
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	memset(dpt, -1, sizeof(dpt));
	int N;
	cin >> N >> K;
	q.push(N);
	dpt[N] = 0;
	dpc[N] = 1;

	while (!q.empty()) {
		int pos = q.front();
		int t = dpt[pos];
		q.pop();

		update(pos, t + 1, pos - 1);
		update(pos, t + 1, pos + 1);
		update(pos, t + 1, pos * 2);
	}

	cout << dpt[K] << "\n" << dpc[K];
}