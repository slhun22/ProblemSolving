#include<iostream>
#include<map>
using namespace std;

struct Node {
	map<string, Node*> childs;
};

void dfs(Node& n, int depth) {
	for (auto& it : n.childs) {
		for (int i = 0; i < depth * 2; i++)
			cout << "-";
		cout << it.first << "\n";

		dfs(*it.second, depth + 1);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int N, K, i, j;
	string s;
	Node root;
	cin >> N;
	for (i = 0; i < N; i++) {
		Node* before = &root;
		cin >> K;
		for (j = 0; j < K; j++) {
			cin >> s;
			if (before->childs.find(s) == before->childs.end())
				before->childs[s] = new Node();

			before = before->childs[s];
		}
	}

	dfs(root, 0);
}