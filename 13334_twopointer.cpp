#include<iostream>
#include<unordered_map>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

set<int> s; //좌표
vector<int> entered; //0 : 진입x, 1 : head만 진입, 2: tail까지 진입 
unordered_map<int, vector<int>> head;
unordered_map<int, vector<int>> tail;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, i, a, b, L;
	cin >> n;
	entered = vector<int>(n);
	for (i = 0; i < n; i++) {
		cin >> a >> b;
		if (a > b)
			swap(a, b);

		head[a].push_back(i);
		tail[b].push_back(i);
		s.insert(a);
		s.insert(b);
	}

	cin >> L;
	
	auto p = s.begin();
	auto q = s.begin();
	int len = 0, ans = -1, cnt = 0;
	while (q != s.end()) {
		len = *q - *p;

		if (len > L) {
			auto& v = head[*p];
			for (auto id : v) {
				if (entered[id] == 2)
					cnt--;
				entered[id] = 0;
			}
			++p;
		}
		else {
			const auto& tv = tail[*q];
			for (auto id : tv) {
				if (entered[id] == 1) {
					entered[id] = 2;
					cnt++;
				}
			}
			ans = max(ans, cnt);

			const auto& hv = head[*q];
			for (auto id : hv)
				entered[id] = 1;

			++q;
		}
	}

	cout << ans;
}