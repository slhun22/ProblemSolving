#include<iostream>
#include<queue>
using namespace std;

int cache[100001];
priority_queue<pair<int, int>, vector<pair<int ,int>>, greater<pair<int ,int>>> pq; //sec point

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int i, s, e;
	cin >> s >> e;
	for (i = 0; i < 100001; i++)
		cache[i] = 2100000000;

	pq.push({ 0, s });
	while (!pq.empty()) {
		auto top = pq.top();
		pq.pop();
		int sec = top.first;
		int point = top.second;

		if (point == e) {
			cout << sec;
			break;
		}

		if (point - 1 >= 0 && cache[point - 1] > sec + 1) {
			cache[point - 1] = sec + 1;
			pq.push({ sec + 1, point - 1 });
		}
		if (point + 1 <= 100000 && cache[point + 1] > sec + 1) {
			cache[point + 1] = sec + 1;
			pq.push({ sec + 1, point + 1 });
		}
		if (point * 2 <= 100000 && cache[point * 2] > sec) {
			cache[point * 2] = sec;
			pq.push({ sec, point * 2 });
		}
	}
}