#include<iostream>
#include<set>
using namespace std;

multiset<int> s;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int i, T, k, num;
	char cmd;
	cin >> T;
	while (T-- > 0) {
		multiset<int>().swap(s);
		cin >> k;
		cin.ignore();
		for (i = 0; i < k; i++) {
			cin >> cmd >> num;
			if (cmd == 'I') {
				s.insert(num);
			}
			else if (cmd == 'D') {
				if (s.empty())
					continue;
				
				if (num == 1)
					s.erase(prev(s.end()));
				else if (num == -1)
					s.erase(s.begin());
			}
		}

		if (s.empty())
			cout << "EMPTY\n";
		else
			cout << *prev(s.end()) << " " << *s.begin() << "\n";
	}
}