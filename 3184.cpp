#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
string board[252];
bool check[252][252];
int R, C,ocnt = 0,vcnt = 0;
int oocnt = 0, vvcnt = 0;
queue<pair<int, int>> q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> R >> C;
	for (int i = 0; i < R; i++) cin >> board[i];

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] != '#' && check[i][j] == false) {
				ocnt = 0;
				vcnt = 0;
				q.push({ i,j });
				check[i][j] = 1;
				if (board[i][j] == 'v') vcnt++;
				else if (board[i][j] == 'o') ocnt++;
				while (!q.empty()) {
					auto cur = q.front();
					q.pop();
					for (int i = 0; i < 4; i++) {
						int nx = cur.first + dx[i];
						int ny = cur.second + dy[i];
						if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
						if (check[nx][ny] == true || board[nx][ny] == '#') continue;
						if (board[nx][ny] == 'v' && check[nx][ny] == false) vcnt++;
						if (board[nx][ny] == 'o' && check[nx][ny] == false) ocnt++;
						check[nx][ny] = 1;
						q.push({ nx,ny });
					}
				}
				if (vcnt >= ocnt) vvcnt += vcnt;
				else oocnt += ocnt;
			}
		}
	}
	cout << oocnt << ' ' << vvcnt;
}
