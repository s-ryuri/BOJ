#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
using vi = vector<int>;
vi adj[32003];
int indeg[32003];
int n;

void topo_sort() {
	priority_queue<int,vi,greater<int>> q;
	vi result;
	for (int i = 1; i <= n; i++) if (indeg[i] == 0) q.push(i);
	while (!q.empty()) {
		int cur = q.top();
		q.pop();
		result.push_back(cur);
		for (int i = 0; i < adj[cur].size(); i++) {
			int nxt = adj[cur][i];
			indeg[nxt]--;
			if (indeg[nxt] == 0) q.push(nxt);
		}
	}
	for (auto& x : result) cout << x << " ";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int M,a,b;
	vi v;
	cin >> n >> M;
	while (M--) {
		cin >> a >> b;
		adj[a].push_back(b);
		indeg[b]++;
	}
	topo_sort();

	
}
