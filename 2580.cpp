#include<iostream>
#include<stack>
#include<vector>
#include<string>

using namespace std;

struct History {
    int r;
    int c;
    int num;
};

int board[9][9];
stack<History> historyStack;
vector<pair<int, int>>blankcache;

bool Able(int num, int r, int c) {
    int i, j;
    for (i = 0; i < 9; i++) { //행 스캔
        if (board[r][i] == num && i != c)
            return false;
    }
    for (i = 0; i < 9; i++) { //열 스캔
        if (board[i][c] == num && i != r)
            return false;
    }
    int blockR = (r / 3) * 3;
    int blockC = (c / 3) * 3;
    for (i = blockR; i < blockR + 3; i++) { //3x3 스캔
        for (j = blockC; j < blockC + 3; j++) {
            if (board[i][j] == num && i != r && j != c)
                return false;
        }
    }
    return true;
}

int GetNumber(int startNum, int r, int c) {
    int i;
    for (i = startNum; i < 10; i++) {
        if (Able(i, r, c)) {
            History history = { r, c, i };
            historyStack.push(history);
            return i;
        }
    }
    return -1;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) {
                blankcache.push_back({ i, j });
            }
        }
    }
    bool isComplete = false;
    int pointer = 0;
    int startNum = 1;

    while (!isComplete) {
        pair<int, int> pos = blankcache[pointer];
        int num = GetNumber(startNum, pos.first, pos.second);
        if (num > 0) { //들어갈 수 있는 숫자가 존재
            board[pos.first][pos.second] = num;
            if (blankcache.back() == pos)
                isComplete = true;
            pointer++;
            startNum = 1;
        }
        else { //들어갈 수 있는 숫자가 없음
            pointer--;
            History trace = historyStack.top();
            historyStack.pop();
            if (blankcache[pointer] == make_pair(trace.r, trace.c)) {
                board[trace.r][trace.c] = 0;
                startNum = trace.num + 1;
            }
        }
    }

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}