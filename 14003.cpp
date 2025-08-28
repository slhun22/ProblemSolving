#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

struct dat {
	int num;
	int idx;

	bool operator< (const dat& other) const {
		return num < other.num;
	}
};

int seq[1000000];
int p[1000000];//idx°ª
stack<int> st;
vector<dat> res;

void stpush(int idx) {
	st.push(seq[idx]);
	if (p[idx] == -1)
		return;
	stpush(p[idx]);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N, i;
	cin >> N;
	cin >> seq[0];
	res.push_back({ seq[0], 0 });
	p[0] = -1;
	for (i = 1; i < N; i++) {
		cin >> seq[i];
		if (res.back().num < seq[i]) {
			p[i] = res.back().idx;
			res.push_back({ seq[i], i });
		}
		else {
			auto it = lower_bound(res.begin(), res.end(), dat{ seq[i], i });
			*it = { seq[i], i };

			if (it != res.begin())
				p[i] = (*prev(it)).idx;
			else
				p[i] = -1;
		}
	}

	cout << res.size() << "\n";
	stpush(res.back().idx);
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
}