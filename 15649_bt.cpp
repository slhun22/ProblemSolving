#include<iostream>
using namespace std;

int N, M;
int arr[9];
bool visited[9];

void next(int idx) {
	int i;
	if (idx == M) {
		for (i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (i = 1; i <= N; i++) {
			if (!visited[i]) {
				visited[i] = true;
				arr[idx] = i;
				next(idx + 1);
				visited[i] = false;
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> M;
	next(0);
}