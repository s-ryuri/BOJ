#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int check[51][51] = { 0, };
int board[51][51] = { 0, };
int dx[8] = { -1,0,1,0, -1,-1,1,1};
int dy[8] = { 0,1,0,-1 ,-1,1,1,-1};

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	int h, w; // h 높이 행 w 너비 열
	while (1) {
		int sum = 0;
		queue<pair<int, int>> q;
		cin >> h >> w;
		if (h == 0 && w == 0) break;
		for (int i = 0; i < w; i++)
			for (int j = 0; j < h; j++)
				cin >> board[i][j];
		for (int i = 0; i < w; i++)
			for (int j = 0; j < h; j++)
				check[i][j] = 0;
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				if (board[i][j] == 1 && check[i][j] == 0) {
					sum++;
					check[i][j] = 1;
					q.push({ i,j });
					while (!q.empty()) {
						auto cur = q.front();
						q.pop();
						for (int dir = 0; dir < 8; dir++) {
							int nx = cur.first + dx[dir];
							int ny = cur.second + dy[dir];
							if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
							if (check[nx][ny] || board[nx][ny] == 0) continue;
							q.push({ nx,ny });
							check[nx][ny] = 1;
						}
					}
				}
			}
		}
		cout<< sum << "\n";
	}
}
