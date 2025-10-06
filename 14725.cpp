#include<iostream>
#include<unordered_map>
#include<set>
using namespace std;

struct dat {
	string s;
	string id;

	bool operator<(const dat& other) const {
		return s < other.s;
	}
};

struct pair_hash {
	size_t operator()(const pair<int, string>& p) const noexcept {
		size_t f = hash<int>()(p.first);
		size_t s = hash<string>()(p.second);
		return f ^ (s << 1);
	}
};

unordered_map<pair<int, string>, set<dat>, pair_hash> m;

void dfs(dat d, int depth) {
	for (int i = 0; i < depth * 2; i++)
		cout << "-";
	cout << d.s << "\n";

	pair<int, string> key = { depth, d.id };
	if (m.find(key) != m.end()) {
		for (auto& val : m[key])
			dfs(val, depth + 1);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N, i, j, K;
	string s;
	cin >> N;
	
	for (i = 0; i < N; i++) {
		cin >> K;

		string id = "";
		for (j = 0; j < K; j++) {
			cin >> s;
			m[{j - 1, id}].insert({ s, id + s });
			id += s;
		}
	}

	for (auto& d : m[{-1, ""}])
		dfs(d, 0);
}