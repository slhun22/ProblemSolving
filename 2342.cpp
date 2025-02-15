#include<iostream>
#include<string>
using namespace std;
int idx = 0;
int seq[100000];
int cost[5][5] = {
	{-1,2,2,2,2},
	{-1,1,3,4,3},
	{-1,3,1,3,4},
	{-1,4,3,1,3},
	{-1,3,4,3,1}
};
int cache[5][5][100000] = { 0, };

int dp(int l, int r, int idx) {
	if (idx == ::idx)
		return 0;
	if (cache[l][r][idx])
		return cache[l][r][idx];
	int left = cost[l][seq[idx]] + dp(seq[idx], r, idx + 1);
	int right = cost[r][seq[idx]] + dp(l, seq[idx], idx + 1);
	return cache[l][r][idx] = min(left, right);
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int i=0;
	string s;
	getline(cin, s);
	while (true) {
		if (s[i] == ' ') {
			i++;
			continue;
		}			
		else if (s[i] == '0')
			break;
		else
			seq[idx++] = s[i++] - '0';
	}
	cout << dp(0, 0, 0);
}