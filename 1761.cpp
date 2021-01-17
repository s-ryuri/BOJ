#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 40001
#define PMAX 25
vector<pair<int,int>> v[MAX];
int d[MAX] = { 0, };
int d2[MAX] = { 0, };
int arr[MAX][PMAX + 1];

void bfs() {
	queue<int> q;
	q.push(1);
	d[1] = 1;
	d2[1] = 0;
	arr[1][0] = -1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int nxt = v[cur][i].first;
			if (d[nxt] == 0) {
				arr[nxt][0] = cur;
				d[nxt] = d[cur] + 1; //깊이
				d2[nxt] = d2[cur] + v[cur][i].second;
				q.push(nxt);
			}
		}
	}
}
void getP(int n) {
	for (int j = 1; (1 << j) < n; j++) {
		for (int i = 1; i <= n; i++) {
			if (arr[i][j - 1] != 0)
				arr[i][j] = arr[arr[i][j - 1]][j - 1];
		}
	}
}

int LCA(int a, int b) {
	if (d[a] < d[b]) swap(a, b);

	if (d[a] != d[b]) {
		for (int j = PMAX; j >= 0; j--) {
			if (d[a] - (1 << j) >= d[b]) {
				a = arr[a][j];
			}
		}
	}

	if (a == b) return a;
	else {
		for (int j = PMAX; j >= 0; j--) {
			if (d[a] - (1 << j) >= 0 && arr[a][j] != arr[b][j]) {
				a = arr[a][j];
				b = arr[b][j];
			}
		}
	}
	return arr[a][0];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, a, b,c ,m;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	bfs();
	getP(n);
	cin >> m;
	int u, v;
	while (m--) {
		cin >> u >> v;
		cout <<  d2[u] + d2[v] - 2 * d2[LCA(u, v)] << "\n";
	}
}
