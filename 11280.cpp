#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#define MAX 10002
using namespace std;

int N, M, cnt, scc,SC,dist[MAX * 2], sc[MAX * 2];
vector<int> adj[MAX * 2];
bool finished[MAX * 2];
stack<int> s;

inline int oppo(int n) { return n % 2 ? n - 1 : n + 1; }
int SccDFS(int cur) {
	dist[cur] = ++cnt;
	s.push(cur);
	int result = dist[cur];
	for (int nxt : adj[cur]) {
		if (dist[nxt] == 0) result = min(result, SccDFS(nxt));
		else if (!finished[nxt]) result = min(result, dist[nxt]);
	}
	if (result == dist[cur]) {
		while (1) {
			int t = s.top();
			s.pop();
			finished[t] = true;
			sc[t] = SC;
			if (t == cur) break;
		}
		SC++;
	}
	return result;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a = (a < 0 ? -(a + 1) * 2 : a * 2 - 1);
		b = (b < 0 ? -(b + 1) * 2 : b * 2 - 1);
		adj[oppo(a)].push_back(b);
		adj[oppo(b)].push_back(a);
	}
	for (int i = 0; i <= 2 * N; i++)
		if (dist[i] == 0) SccDFS(i);

	for (int i = 0; i < N; i++) {
		if (sc[i * 2] == sc[i * 2 + 1]) {
			cout << "0";
			return 0;
		}
	}
	cout << 1;
}
