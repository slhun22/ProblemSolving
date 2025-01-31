#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[100001];
bool visited[100001];
int parent[100001];
queue<int> q;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int N, i, a, b;	

	cin >> N;
	for (i = 0; i < N - 1; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	q.push(1);
	while (!q.empty()) {
		int num = q.front();
		q.pop();
		for (int iter : graph[num]) {
			if (!visited[iter]) {
				parent[iter] = num;
				visited[iter] = true;
				q.push(iter);
			}
		}
	}

	for (i = 2; i <= N; i++)
		cout << parent[i] << "\n";
}