#include <iostream>
#include <queue>
#include <string>
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
string board[22];
bool check[22][22] = { 0, };
bool alpha[26] = { 0, };
int cnt = 0;
int R, C;
void back(int a, int b, int c) {
	cnt = max(cnt, c);
	check[a][b] = 1;
	alpha[board[a][b] - 'A'] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = a + dx[i];
		int ny = b + dy[i];
		if (nx < 0 || nx >= R || ny < 0 || ny >= C)continue;
		if (check[nx][ny]) continue;
		if (!alpha[board[nx][ny] - 'A']) back(nx, ny, c + 1);
	}
	check[a][b] = 0;
	alpha[board[a][b] - 'A'] = 0;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> R >> C;
	for (int i = 0; i < R; i++) cin >> board[i];
	back(0, 0, 1);
	cout << cnt;
}
