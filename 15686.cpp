#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, M, ans = 2140000000;
int field[50][50];
int distcache[100][13]; //home-chicken
bool selected[13];
vector<pair<int, int>> cv;
vector<pair<int, int>> hv;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int i, j, ans = 2140000000;
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> field[i][j];
			if (field[i][j] == 1)
				hv.push_back({ i, j });
			if (field[i][j] == 2)
				cv.push_back({ i, j });
		}
	}

	for (i = 0; i < hv.size(); i++)
		for (j = 0; j < cv.size(); j++)
			distcache[i][j] = abs(hv[i].first - cv[j].first) + abs(hv[i].second - cv[j].second);

	vector<int> filter(cv.size());
	fill(filter.rbegin(), filter.rbegin() + M, 1);
	do {
		int citydist = 0;
		for (int i = 0; i < hv.size(); i++) {
			int mindist = 2140000000;
			for (int j = 0; j < cv.size(); j++) {
				if (filter[j]) {
					if (distcache[i][j] < mindist)
						mindist = distcache[i][j];
				}
			}
			citydist += mindist;
		}

		if (citydist < ans)
			ans = citydist;
	} while (next_permutation(filter.begin(), filter.end()));
	cout << ans;
}