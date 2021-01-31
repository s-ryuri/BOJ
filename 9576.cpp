#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 1003
using namespace std;

vector<int> adj[MAX];
bool check[MAX];
int d[MAX];

bool dfs(int cur) {
	for (int nxt : adj[cur]) {
		if (check[nxt]) continue;
		check[nxt] = true;
		if (d[nxt] == 0 || dfs(d[nxt]) ){
			d[nxt] = cur;
			return true;
		}
	}
	return false;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T, N, M, a, b;
	cin >> T;
	while (T--) {
		int cnt = 0;
		cin >> N >> M;
		for (int i = 1; i <= M; i++) {
			cin >> a >> b;
			for (int j = a; j <= b; j++) {
				adj[i].push_back(j);
			}
		}

		for (int i = 1; i <= M; i++) {
			fill(check, check + MAX, false);
			if (dfs(i)) cnt++;
		}

		for (int i = 0; i <= M; i++) {
			adj[i].clear();
		}
		fill(d, d + MAX, 0);
		cout << cnt << "\n";
	}
}
