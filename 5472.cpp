#include <iostream>
#include <queue>
using namespace std;
#define MAX 1003
using pi = pair<int, int>;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
int firedist[MAX][MAX];
int sangdist[MAX][MAX];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t,w,h;
	cin >> t;
	while (t--) {
		bool a = false;
		cin >> w >> h;
		string board[MAX];
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				firedist[i][j] = -1;
				sangdist[i][j] = -1;
			}
		}
		for (int i = 0; i < h; i++) cin >> board[i];
		queue<pi> fire;
		queue<pi> sang;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (board[i][j] == '*') {
					fire.push({ i,j });
					firedist[i][j] = 0;
				}
				if (board[i][j] == '@') {
					sang.push({ i,j });
					sangdist[i][j] = 0;
				}
			}
		}
		while (!fire.empty()) {
			auto cur = fire.front();
			fire.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if (board[nx][ny] == '#' || firedist[nx][ny] != -1) continue;
				firedist[nx][ny] = firedist[cur.first][cur.second] + 1;
				fire.push({ nx,ny });
			}
		}
		while (!sang.empty()) {
			auto cur = sang.front();
			sang.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
					cout << sangdist[cur.first][cur.second] + 1 << "\n";
					a = true;
					break;
				}
				if(board[nx][ny]== '#' || board[nx][ny] == '*') continue;
				if (sangdist[nx][ny] != -1) continue;
				if ((sangdist[cur.first][cur.second] + 1 >= firedist[nx][ny]) && firedist[nx][ny] != -1) continue;
				sangdist[nx][ny] = sangdist[cur.first][cur.second] + 1;
				sang.push({ nx,ny });
			}
			if (a) break;
		}
		if (!a) cout << "IMPOSSIBLE" << "\n";
	}
}
