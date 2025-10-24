#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool visited[51];
bool partyVisited[51];
vector<int> party[51];
vector<int> partyAdj[51]; //사람들마다 참여하는 파티의 인덱스
queue<int> q;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N, M, R, temp;
	cin >> N >> M >> R;
	for (int i = 0; i < R; i++) {
		cin >> temp;
		q.push(temp);
		visited[temp] = true;
	}

	for (int i = 1; i <= M; i++) {
		cin >> R;
		for (int j = 0; j < R; j++) {
			cin >> temp;
			partyAdj[temp].push_back(i);
			party[i].push_back(temp);
		}
	}

	while (!q.empty()) {
		int num = q.front();
		q.pop();

		for (auto partyIdx : partyAdj[num]) {
			if (partyVisited[partyIdx])
				continue;

			partyVisited[partyIdx] = true;
			for (auto person : party[partyIdx]) {
				if (!visited[person]) {
					visited[person] = true;
					q.push(person);
				}
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= M; i++) {
		if (!partyVisited[i])
			ans++;
	}
	cout << ans;
}