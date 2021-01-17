#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;
#define PMAX 25
#define MAX 100001

vector<int> adj[MAX];
int d[MAX] = { 0, };
int p[MAX][PMAX] = { 0, };
void bfs(int s) {
	queue<int> q;
	q.push(s);
	d[s] = 1;
	p[s][0] = -1; // 1 기준
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < adj[cur].size(); i++) {
			int nxt = adj[cur][i];
			if (d[nxt] == 0) {
				p[nxt][0] = cur;
				d[nxt] = d[cur] + 1;
				q.push(nxt);
			}
		}
	}
	//BFS를 통해서 구한건 각 노드의 첫 번째 부모 노드와 해당 노드의 깊이
}

void getP(int n) { // 특정 노드의 2^j번째 부모를 찾는 함수
	for (int j = 1; (1 << j) < n; j++) {
		for (int i = 1; i <= n; i++) {
			if (p[i][j - 1] != 0) p[i][j] = p[p[i][j - 1]][j - 1];
		}
	}
	//1 i번노드의 2^j -1번째 부모 노드를 확인
	//만약 0이 아니라면 i번 노드의 2j번째 부모는, i번 노드의 2 j - 1번째 부모노드의  2 j - 1 번째 부모노드
}

int LCA(int a, int b) {
	if (d[a] < d[b])
		swap(a, b);
	if (d[a] != d[b])
		for (int j = PMAX; j >= 0; --j)
			if (d[a] - (1 << j) >= d[b])
				a = p[a][j];
	if (a == b)
		return a;
	else {
		for (int j = PMAX; j >= 0; --j) {
			if (d[a] - (1 << j) >= 0 && p[a][j] != p[b][j]) {
				a = p[a][j];
				b = p[b][j];
			}
		}
	}
	return p[a][0];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M, a, b;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	bfs(1);
	getP(N);
	cin >> M;
	while (M--) {
		cin >> a >> b;
		cout << LCA(a, b) << "\n";
	}
}
