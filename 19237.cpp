#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

struct shk {
	int r;
	int c;
	int dir; //보는 방향 (이동방향 아님!)
};
//위 아 왼 오
int N, M, K;
int field[21][21];
int tmpfield[21][21]; //이동 결산용
pair<int,int> smell[21][21];//idx-time
shk sharks[401];
bool dead[401];
int deadcnt = 0;
int dpr[401][4][4];
int dx[4] = { -1, 1, 0 , 0 };
int dy[4] = { 0, 0, -1, 1 };

void move(int idx, vector<int>& deadv) {
	int r = sharks[idx].r;
	int c = sharks[idx].c;
	int dir = sharks[idx].dir;

	bool finished = false;
	for (int i = 0; i < 4; i++) { //냄새 없는 칸 탐색
		int d = dpr[idx][dir][i]; //우선순위 방향
		int nr = r + dx[d];
		int nc = c + dy[d];

		if (nr < 1 || nr > N || nc < 1 || nc > N)
			continue;

		if (smell[nr][nc].first == 0) {
			if (tmpfield[nr][nc] == 0) {
				tmpfield[nr][nc] = idx;
				sharks[idx].r = nr;
				sharks[idx].c = nc;
				sharks[idx].dir = d;
			}
			else
				deadv.push_back(idx);
			
			finished = true;
			break;
		}
	}

	if (finished)
		return;

	for (int i = 0; i < 4; i++) { //자기 냄새 칸 탐색
		int d = dpr[idx][dir][i]; //우선순위 방향
		int nr = r + dx[d];
		int nc = c + dy[d];

		if (nr < 1 || nr > N || nc < 1 || nc > N)
			continue;

		if (smell[nr][nc].first == idx) {
			if (tmpfield[nr][nc] == 0) {
				tmpfield[nr][nc] = idx;
				sharks[idx].r = nr;
				sharks[idx].c = nc;
				sharks[idx].dir = d;
			}
			else
				deadv.push_back(idx);
			break;
		}
	}
}

void move_all() {
	memset(tmpfield, 0, sizeof(tmpfield));
	vector<int> deadv;
	for (int i = 1; i <= M; i++) {
		if (!dead[i])
			move(i, deadv);
	}
	memcpy(field, tmpfield, sizeof(field));

	for (auto iter : deadv) {
		dead[iter] = true;
		deadcnt++;
	}
}

void smell_update() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (smell[i][j].first > 0)
				smell[i][j].second--;

			if (smell[i][j].second == 0)
				smell[i][j].first = 0;
		}
	}

	for (int i = 1; i <= M; i++) {
		if(!dead[i])
			smell[sharks[i].r][sharks[i].c] = { i, K };
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> M >> K;
	int i, j, k, tmp;
	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++) {
			cin >> field[i][j];
			if (field[i][j] > 0)
				sharks[field[i][j]] = { i, j, -1 };
		}

	for (i = 1; i <= M; i++) {
		cin >> tmp;
		sharks[i].dir = tmp - 1;
	}

	for (i = 1; i <= M; i++) {
		for (j = 0; j < 4; j++) {
			for (k = 0; k < 4; k++) {
				cin >> tmp;
				dpr[i][j][k] = tmp - 1;
			}		
		}
	}

	for (i = 1; i <= M; i++) //루프 전 초기에 냄새 뿌리기
		smell[sharks[i].r][sharks[i].c] = { i, K };

	int t = 0;
	while (t < 1000) {
		move_all();
		smell_update();
		t++;
		if (deadcnt == M - 1) {
			cout << t;
			return 0;
		}
	}

	cout << -1;
}