#include<iostream>
#include<queue>
using namespace std;

priority_queue<int> mx; //중간값이하의 값을 담아놓는 우선순위 큐 (top이 중간값)
priority_queue<int, vector<int>, greater<int>> mn; //중간값 초과의 값을 담아놓는 우선순위 큐 (top이 중간값 다음 값)

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N, i, n;
	cin >> N;

	for (i = 0; i < N; i++) {
		cin >> n;

		if (mx.empty() && mn.empty())
			mx.push(n);
		else if (mx.size() == mn.size() + 1)
			mn.push(n);
		else
			mx.push(n);

		if (!mx.empty() && !mn.empty() && mx.top() > mn.top()) {
			int mxtop = mx.top();
			int mntop = mn.top();
			mx.pop();
			mn.pop();
			mx.push(mntop);
			mn.push(mxtop);
		}

		cout << mx.top() << "\n";
	}
}