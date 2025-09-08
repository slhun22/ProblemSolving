#include<iostream>
#include<vector>
using namespace std;

class node {
public:
	node(int val) : value(val) {}

	int value;
	node* blue = nullptr;
	node* red = nullptr;
};

vector<node> nv;
vector<node> sidev;

node* dfs(node* n, int cur_cnt, int cnt) {
	if (cur_cnt == cnt || n == nullptr)
		return n;

	return dfs(n->red, cur_cnt + 1, cnt);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int i;
	int dice[10];

	nv.reserve(21);
	sidev.reserve(11);
	nv.emplace_back(0);
	for (i = 1; i <= 20; i++)		
		nv.emplace_back(i * 2);

	for (i = 0; i < 20; i++)
		nv[i].red = &nv[i + 1];

	sidev.emplace_back(13);
	sidev.emplace_back(16);
	sidev.emplace_back(19);
	sidev.emplace_back(25);//3
	nv[5].blue = &sidev[0];
	for (i = 0; i < 3; i++)
		sidev[i].red = &sidev[i + 1];
	sidev.emplace_back(22);//4
	sidev.emplace_back(24);//5
	nv[10].blue = &sidev[4];
	sidev[4].red = &sidev[5];
	sidev[5].red = &sidev[3];
	sidev.emplace_back(30);//6
	sidev.emplace_back(35);//7
	sidev[3].red = &sidev[6];
	sidev[6].red = &sidev[7];
	sidev[7].red = &nv[20];
	sidev.emplace_back(28);//8
	sidev.emplace_back(27);//9
	sidev.emplace_back(26);//10
	nv[15].blue = &sidev[8];
	sidev[8].red = &sidev[9];
	sidev[9].red = &sidev[10];
	sidev[10].red = &sidev[3];

	for (i = 0; i < 10; i++)
		cin >> dice[i];

	int ans = -1;
	for (int st = 0; st < (1 << (10 * 2)); st++) {
		node* pos[4];
		for (i = 0; i < 4; i++)
			pos[i] = &nv[0];
		int temp = st;
		int score = 0;
		bool impossible = false;
		for (i = 0; i < 10; i++) {
			int target = temp % 4;
			temp /= 4;

			if (pos[target] == nullptr)
				break;

			pos[target] = (pos[target]->blue != nullptr) ? dfs(pos[target]->blue, 1, dice[i]) : dfs(pos[target]->red, 1, dice[i]);
			if (pos[target] != nullptr) {
				for (int j = 0; j < 4; j++) {
					if (target == j || pos[j] == nullptr)
						continue;

					if (pos[target] == pos[j]) {
						impossible = true;
						break;
					}
				}

				if (impossible)
					break;

				score += pos[target]->value;
			}
		}

		if (ans < score && !impossible)
			ans = score;
	}

	cout << ans;
}