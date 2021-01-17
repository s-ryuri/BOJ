#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int M, N;
	string board[1004];
	int check[1004][1004] = { 0, };
	queue<pair<int, int>> q;
	cin >> M >> N;
	for (int i = 0; i < M; i++)
			cin >> board[i];
	for (int j = 0; j < N; j++) {
		if (board[0][j] == '0' && check[0][j] == 0) {
			check[0][j] = 1;
			board[0][j] = '2';
			q.push({ 0,j });
			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = cur.first + dx[i];
					int ny = cur.second + dy[i];
					if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
					if (board[nx][ny] == '1' || check[nx][ny] == 1)continue;
					if (nx == M - 1 && board[nx][ny] == '0') {
						cout << "YES";
						return 0;
					}
					check[nx][ny] = 1;
					board[nx][ny] = '2';
					q.push({ nx,ny });
				}
			}
		}
	}
	cout << "NO";
}
