#include<iostream>
#include<stack>
using namespace std;

int arr[1000000];
stack<int> st;
stack<int> print_st;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N, i;
	cin >> N;
	for (i = 0; i < N; i++)
		cin >> arr[i];

	for (i = N - 1; i >= 0; i--) {
		while (!st.empty()) {
			if (arr[i] < st.top()) {
				print_st.push(st.top());
				st.push(arr[i]);
				break;
			}
			else
				st.pop();
		}

		if (st.empty()) {
			print_st.push(-1);
			st.push(arr[i]);
		}
	}

	while (!print_st.empty()) {
		cout << print_st.top() << " ";
		print_st.pop();
	}
}