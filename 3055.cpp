#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

using pi = pair<int, int>;
#define X first
#define Y second

int R, C;
string board[52];
int dist[52][52];
int dist2[52][52];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int x = -1, y = -1;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue < pair<int, int>> q;
	queue < pair<int, int>> q2;
	for (int i = 0; i < 52; i++)
		for (int j = 0; j < 52; j++) {
			dist[i][j] = -1;
			dist2[i][j] = -1;
		}
			
	cin >> R >> C;
	for (int i = 0; i < R; i++) cin >> board[i];
	/*일단 * 물이 차 있는 지역부터 BFS를 돌림*/
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] == '*') {
				q.push({ i,j });
				dist[i][j] = 0;
			}
			if (board[i][j] == 'S') {
				q2.push({ i,j });
				dist2[i][j] = 0;
			}if (board[i][j] == 'D') {
				x = i;
				y = j;
			}
		}
			
	}

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if (board[nx][ny] == 'X' || board[nx][ny] == 'D'|| dist[nx][ny] != -1) continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			q.push({ nx,ny });
		}
	}
	
	while (!q2.empty()) {
		auto cur = q2.front();
		q2.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			//cout << "nx : " << nx << " ny : " << ny << "\n";
			if (nx == x && ny == y) {
				dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
				cout << dist2[nx][ny];
				return 0;
			}
			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if (board[nx][ny] == 'X' || dist2[nx][ny] != -1|| board[nx][ny] == '*') continue;
			if (dist2[cur.X][cur.Y] + 1 >= dist[nx][ny] && dist[nx][ny] != -1) continue;
			dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
			q2.push({ nx,ny });
		}
	}
	cout << "KAKTUS";
}
