#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	vector<int> result;
	vector<int> childs[1001];
	int parentCnt[1001] = { 0, };
	int temp[1000];
	queue<int> q;	
	int N, M, i, j, seqN;
	cin >> N >> M;

	for (i = 0; i < M; i++) {
		cin >> seqN;
		for (j = 0; j < seqN; j++)
			cin >> temp[j];
		for (j = 0; j < seqN - 1; j++) {
			parentCnt[temp[j + 1]]++;
			childs[temp[j]].push_back(temp[j + 1]);
		}
	}

	for (i = 1; i <= N; i++)
		if (parentCnt[i] == 0)
			q.push(i);

	while (!q.empty()) {
		int front = q.front();
		q.pop();
		result.push_back(front);
		for (auto child : childs[front]) {
			parentCnt[child]--;
			if (parentCnt[child] == 0)
				q.push(child);
		}
	}

	if (result.size() < N)
		cout << 0;
	else {
		for (auto iter : result)
			cout << iter << "\n";
	}
}