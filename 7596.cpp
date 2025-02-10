#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
    int i, j, n, cnt = 1;
    string s;
    vector<string> sv;
    while (true) {
        cin >> n;
        cin.ignore();
        if (!n)
            break;
        for (i = 0; i < n; i++) {
            getline(cin, s);
            sv.push_back(s);
        }
        sort(sv.begin(), sv.end());
        cout << cnt++ << "\n";
        for (auto str : sv)
            cout << str << "\n";
        vector<string>().swap(sv);
    }
}