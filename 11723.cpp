#include<iostream>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int i, M, x, s = 0;
	cin >> M;
	string cmd;
	for (i = 0; i < M; i++) {
		cin >> cmd;
		if (cmd == "all") s = (1 << 21) - 1;
		else if (cmd == "empty") s = 0;
		else {
			cin >> x;
			if (cmd == "add") s |= 1 << x;
			else if (cmd == "remove") s &= ~(1 << x);
			else if (cmd == "check") cout << ((s >> x) & 1) << "\n";
			else if (cmd == "toggle") s ^= 1 << x;
		}
	}
}