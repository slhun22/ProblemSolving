#include<iostream>
#include<vector>
#include<stack>
#include<list>

using namespace std;

vector<int> parent[1001];
int cost[1001];
int cache[1001];
stack<int> st;
list<int> q;
list<int>::iterator qcache[1001];

void PushParent(int num) {
	for (int i = 0; i < 1001; i++) {
		qcache[i] = q.end();
	}
	q.push_back(num);
	qcache[num] = prev(q.end());
	while (!q.empty()) {
		int n = q.front();
		q.pop_front();
		qcache[n] = q.end();
		st.push(n);
		if (!parent[n].empty()) {
			for (auto iter : parent[n]) {		
				q.push_back(iter);
				if (qcache[iter] != q.end()) {
					q.erase(qcache[iter]);
				}
				qcache[iter] = prev(q.end());
			}
		}
	}	
}

void FillCache() {
	int max;
	while (!st.empty()) {
		max = -1;
		int num = st.top();
		st.pop();
		if (parent[num].empty()) {
			cache[num] = cost[num];
		}
		else {
			for (auto iter : parent[num]) {
				if (cache[iter] > max)
					max = cache[iter];
			}
			cache[num] = max + cost[num];
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int i, j, T, N, K, W, X, Y;

	cin >> T;

	while (T-- > 0) {
		for (auto& iter : parent) {
			vector<int>().swap(iter);
		}
		cin >> N >> K;
		for (i = 1; i <= N; i++) {
			cin >> cost[i];
		}
		for (i = 0; i < K; i++) {
			cin >> X >> Y;
			parent[Y].push_back(X);
		}
		cin >> W;
		PushParent(W);
		FillCache();
		cout << cache[W] << "\n";
	}
}