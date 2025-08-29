#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

class min_heap {
public:
	int top() {
		return tree[0];
	}

	void push(int num) {
		tree[++end] = num;
		change_push(end);
	}

	void pop() {
		tree[0] = tree[end--];
		change_pop(0);
	}

	bool empty() {
		return end == -1;
	}

private:
	void change_push(int idx) {
		if (idx == 0)
			return;

		int parent;
		if (idx % 2)
			parent = (idx - 1) / 2;
		else
			parent = (idx - 2) / 2;

		if (tree[idx] < tree[parent]) {
			swap(tree[idx], tree[parent]);
			change_push(parent);
		}
	}

	void change_pop(int idx) {
		int lchild = idx * 2 + 1;
		int rchild = idx * 2 + 2;
		if (lchild > end)
			return;

		int next = lchild;
		if(rchild <= end)
			next = (tree[lchild] < tree[rchild]) ? lchild : rchild;

		if (tree[idx] > tree[next]) {
			swap(tree[idx], tree[next]);
			change_pop(next);
		}
	}

	int tree[100000];
	int end = -1;
};

min_heap mh;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N, i, n;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> n;
		if (n == 0) {
			if (mh.empty())
				cout << "0\n";
			else {
				cout << mh.top() << "\n";
				mh.pop();
			}
		}
		else
			mh.push(n);
	}
}