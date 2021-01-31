#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define MAX 402
#define INT 1e9
using namespace std;

vector<int> adj[MAX];
int capa[MAX][MAX], flow[MAX][MAX];
int d[MAX];
int N, P,result = 0;

void networkflow(int start, int end) {
	while (1) {
		fill(d, d + MAX, -1);
		queue<int> q;
		q.push(start);
		while (!q.empty() && d[end] == -1) {
			int cur = q.front();
			q.pop();
			for (int nxt : adj[cur]) {
				if (capa[cur][nxt] - flow[cur][nxt] > 0 && d[nxt] == -1) {
					q.push(nxt);
					d[nxt] = cur;
					if (nxt == end)break;
				}
			}
		}
		if (d[end] == -1) break;
		int flown = INT;
		for (int i = end; i != start; i = d[i]) {
			flown = min(flown, capa[d[i]][i] - flow[d[i]][i]);
		}
		for (int i = end; i != start; i = d[i]) {
			flow[d[i]][i] += flown;
			flow[i][d[i]] -= flown;
		}
		result += flown;
	}
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> P;
	int a, b;
	for (int i = 0; i < P; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		capa[a][b] = 1;
		adj[b].push_back(a);
		capa[b][a] = 0;
	}
	networkflow(1, 2);
	cout << result;
}
