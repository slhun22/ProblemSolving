#include<iostream>
using namespace std;

int cache[1000][3];
int h[1000][3];
int N, first;

pair<int, int> GetColor(int color) {
	if (color == 0) return make_pair(1, 2);
	else if (color == 1) return make_pair(0, 2);
	else return make_pair(0, 1);
}

int dp(int depth, int color) {
	if (cache[depth][color])
		return cache[depth][color];
	if (depth == N - 1) {
		if (color == first)
			return cache[depth][color] = 100000;
		else
			return cache[depth][color] = h[depth][color];
	}
	auto selectColor = GetColor(color);
	int left = dp(depth + 1, selectColor.first);
	int right = dp(depth + 1, selectColor.second);
	return cache[depth][color] = h[depth][color] + min(left, right);
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int i, j, k, result, min = 1000000;
	cin >> N;
	for (i = 0; i < N; i++)
		cin >> h[i][0] >> h[i][1] >> h[i][2];
	for (i = 0; i < 3; i++) {
		for (j = 0; j < N; j++)
			for (k = 0; k < 3; k++)
				cache[j][k] = 0;
		first = i;
		result = dp(0, i);
		if (min > result)
			min = result;
	}
	cout << min;
}