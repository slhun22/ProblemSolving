#include<iostream>
#include<stack>
using namespace std;

int cache[1001][1001] = { 0, };

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int i, j;
	string a, b;
	stack<char> st;
 	cin >> a >> b;
	for (i = 0; i < a.length(); i++) {
		for (j = 0; j < b.length(); j++) {
			if (a[i] == b[j])
				cache[i+1][j+1] = cache[i][j] + 1;
			else
				cache[i+1][j+1] = max(cache[i+1][j], cache[i][j+1]);
		}
	}
	cout << cache[i][j]<<"\n";
	while (cache[i][j]) {
		if (a[i-1] == b[j-1]) {
			st.push(a[i-1]);
			i--; j--;
		}
		else {
			if (cache[i-1][j] <= cache[i][j-1])
				j--;
			else
				i--;
		}
	}
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
}