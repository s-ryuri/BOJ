#include <iostream>
#include <vector>
#define MAX 100003

using namespace std;
int adj[MAX];
bool check[MAX];
bool finished[MAX];

int cnt;
void dfs(int num) {
	check[num] = true;
	int nxt = adj[num];
	if (check[nxt]) {
		if (!finished[nxt]) {
			for (int i = nxt; i != num; i = adj[i]) cnt++;
			cnt++;
		}
	}
	else dfs(nxt);
	finished[num] = true;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> adj[i];
		}
		fill(check, check + n + 1, false);
		fill(finished, finished + n + 1, false);
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (!check[i]) dfs(i);
		}
		cout << n - cnt << "\n";
	}
}
