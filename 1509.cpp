#include<iostream>
#define INF 3000
using namespace std;

string s;
bool dp[2500][2500];
int dp2[2500];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int i, j;
	cin >> s;
	int length = s.length();
	for (i = 0; i < length; i++)
		dp2[i] = INF;

	for (i = 0; i < length - 1; i++) {
		dp[i][i] = true;
		dp[i][i + 1] = (s[i] == s[i + 1]);
	}
	dp[length - 1][length - 1] = true;

	for (i = 2; i < length; i++)
		for (j = 0; j < length - i; j++)
			dp[j][j + i] = dp[j + 1][j + i - 1] && (s[j] == s[j + i]);

	dp2[0] = 1;
	for (i = 1; i < length; i++) {
		if (dp[0][i])
			dp2[i] = 1;
		else {
			for (j = 0; j < i; j++) {
				if(dp[j + 1][i])
					dp2[i] = min(dp2[i], dp2[j] + 1);
			}
		}
	}

	cout << dp2[length - 1];
}