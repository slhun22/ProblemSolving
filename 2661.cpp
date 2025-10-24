#include<iostream>
#include<string_view>
using namespace std;

int N;
string ans;
bool finished = false;

bool check(string& s) {
	for (int i = 1; i <= s.length() / 2; i++) {
		int div = s.length() - i;
		string_view first(s.data() + div - i, i);
		string_view second(s.data() + div, i);
		if (first == second)
			return false;
	}
	return true;
}

void dfs(string s) {
	if (finished)
		return;
	if (s.length() == N) {
		ans = s;
		finished = true;
	}

	string s1 = s + '1';
	string s2 = s + '2';
	string s3 = s + '3';
	if (check(s1))
		dfs(s1);
	if (check(s2))
		dfs(s2);
	if (check(s3))
		dfs(s3);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N;
	string s = "";
	dfs(s);
	cout << ans;
}