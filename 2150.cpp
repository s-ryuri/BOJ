#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#define MAX 10003

using namespace std;
int V, E, cnt = 0, dist[MAX] = { 0, }, scc = 0, sccn[MAX] = { 0, };
vector<int> adj[MAX];
bool finished[MAX];
stack<int> s;
vector<vector<int>> SCC;
int dfs(int cur) {
	dist[cur] = ++cnt;
	s.push(cur);
	int result = dist[cur];
	for (int nxt : adj[cur]) {
		if (dist[nxt] == 0) result = min(result, dfs(nxt));
		else if (!finished[nxt]) result = min(result, dist[nxt]);
	}

	if (result == dist[cur]) {
		vector<int> curSCC;
		while (1) {
			int t = s.top();
			s.pop();
			curSCC.push_back(t);
			finished[t] = true;
			sccn[t] = scc;
			if (t == cur) break;
		}

		sort(curSCC.begin(), curSCC.end());
		SCC.push_back(curSCC);
		scc++;
	}

	return result;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> V >> E;
	int a, b;
	for (int i = 0; i < E; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
	}

	for (int i = 1; i <= V; i++)
		if (dist[i] == 0) dfs(i);
	sort(SCC.begin(), SCC.end());
	cout << scc << "\n";
	for (auto& x : SCC) {
		for (int t : x) {
			cout << t << " ";
		}
		cout << -1 << "\n";
	}
}
