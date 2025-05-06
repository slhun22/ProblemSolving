#include<iostream>
#include<queue>
#define INF 2140000000
using namespace std;

queue<int> q;
vector<int> t(100001, INF);

void move(int pos, int cnt) {
	if (0 <= pos && pos <= 100000 && t[pos] > cnt + 1) { 
		q.push(pos);
		t[pos] = cnt + 1;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int N, K;
	cin >> N >> K;
	q.push(N);
	t[N] = 0;
	while (!q.empty()) {
		int pos = q.front();
		int cnt = t[pos];
		q.pop();
		if (pos == K) {
			cout << t[K];
			break;
		}
		move(pos - 1, cnt);
		move(pos + 1, cnt);
		move(pos * 2, cnt);
	}
}