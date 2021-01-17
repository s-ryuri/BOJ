#include <iostream>
#include <queue>
#include <string>
using namespace std;


string board[1002];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int check[1002][1002][11] = { 0, }; //x,y,z의 거리를 담는 배열
int N, M,K;

struct three {
	int x, y, z;
};

int bfs() {
	queue<three> q;
	check[0][0][0] = 1; //z = 0이면 벽 안 부심
	q.push({ 0,0,0 });
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, z = q.front().z;
		q.pop();
		if (x == N - 1 && y == M - 1) return check[x][y][z];
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int bl = z;
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (check[nx][ny][bl])continue;
			if (board[nx][ny] == '0') {
				check[nx][ny][bl] = check[x][y][bl] + 1;
				q.push({ nx, ny, bl});
			}
			if (board[nx][ny] == '1' && bl < K) {
				check[nx][ny][bl + 1] = check[x][y][bl] + 1;
				q.push({ nx, ny, bl + 1 });
			}
		}
	}

	return -1;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) cin >> board[i];
	cout << bfs();
}
