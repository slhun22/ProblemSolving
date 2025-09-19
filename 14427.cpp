#include<iostream>
#include<set>
#include<string>
#include<vector>
using namespace std;

int arr[100001];
set<pair<int, int>> s; //v-idx

vector<int> split(string s) {
	string buffer = "";
	vector<int> res;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') {
			res.push_back(stoi(buffer));
			buffer = "";
		}
		else
			buffer += s[i];
	}
	res.push_back(stoi(buffer));
	return res;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int i, N, M;
	cin >> N;
	for (i = 1; i <= N; i++) {
		cin >> arr[i];
		s.insert({ arr[i], i});
	}

	cin >> M;
	string input;
	cin.ignore();
	for (i = 1; i <= M; i++) {
		getline(cin, input);
		if (input[0] == '1') {
			vector<int> splited = split(input.substr(2));
			int idx = splited[0];
			int v = splited[1];
			s.erase({ arr[idx], idx });
			s.insert({ v, idx });
			arr[idx] = v;
		}
		else if (input[0] == '2')
			cout << (*s.begin()).second << "\n";
	}
}