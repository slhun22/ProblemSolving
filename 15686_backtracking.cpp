#include<iostream>
#include<vector>
#define MAX 2140000000

using namespace std;

int field[50][50];
vector<pair<int, int>> c;
vector<int> dist[13];
bool isBanned[13];
int M, mindist = MAX;

void back(int leftcnt, int start) {
	int i;
	if (leftcnt == M) {
		int j, sum = 0;
		vector<int> finaldist(dist[0].size(), MAX);
		for (i = 0; i < c.size(); i++) {
			if (!isBanned[i]) {
				for (j = 0; j < dist[i].size(); j++) {
					if (finaldist[j] > dist[i][j])
						finaldist[j] = dist[i][j];
				}
			}
		}
		for (auto iter : finaldist)
			sum += iter;
		if (mindist > sum)
			mindist = sum;
	}
	else {
		for (i = start; i < c.size(); i++) {
			isBanned[i] = true;
			back(leftcnt - 1, i + 1);
			isBanned[i] = false;
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int N, i, j, k;
	cin >> N >> M;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> field[i][j];
			if (field[i][j] == 2)
				c.push_back({ i, j });
		}
	}
	for (i = 0; i < c.size(); i++) {
		int sum = 0;
		for (j = 0; j < N; j++) {
			for (k = 0; k < N; k++) {
				if (field[j][k] == 1) {
					int distance = abs(c[i].first - j) + abs(c[i].second - k);
					dist[i].push_back(distance);
				}
			}
		}
	}
	back(c.size(), 0);
	cout << mindist;
}