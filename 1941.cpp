#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#define MAX 502
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int ycnt = 0, scnt = 0;
string board[7];
int result = 0;
bool selec[27];
int adjboard[6][6];
bool adjcheck[6][6];

bool adj() {
	int cnt = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < 25; i++) {
		if (selec[i]) {
			adjboard[i / 5][i % 5] = 1;
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (adjboard[i][j] && !adjcheck[i][j]) {
				cnt++;
				if (board[i][j] == 'Y') ycnt++;
				else scnt++;
				adjcheck[i][j] = true;
				q.push({ i,j });
				while (!q.empty()) {
					auto cur = q.front();
					q.pop();
					for (int i = 0; i < 4; i++) {
						int nx = cur.first + dx[i];
						int ny = cur.second + dy[i];
						if (nx < 0 || ny > 5 || ny < 0 || nx > 5) continue;
						if (adjboard[nx][ny] == 0 || adjcheck[nx][ny]) continue;
						adjcheck[nx][ny] = true;
						if (board[nx][ny] == 'Y') ycnt++;
						else scnt++;
						q.push({ nx,ny });
					}
				}
			}
		}
	}
	if (cnt == 1) return true;
	else return false;
}

void init() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			adjboard[i][j] = 0;
			adjcheck[i][j] = 0;
		}
	}
}
void johab(int idx, int cnt) { //7개를 뽑는 경우의 수
	if (cnt == 7) {
		ycnt = scnt = 0;
		if (adj()) {
			if (scnt >= 4) result++;
		}
		init();
		return;
	}
	for (int i = idx; i < 25; i++) {
		if (!selec[i]) {
			selec[i] = true;
			johab(i, cnt + 1);
			selec[i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 5; i++) cin >> board[i];
	johab(0, 0);
	cout << result;
}
