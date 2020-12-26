#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[1001];
vector<int> vtime;
int indegree[1001] = { 0, },N;

void we_sort();

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(nullptr);
	int T, K,X,Y,num;
	cin >> T;
	while (T--) {
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			cin >> num;
			vtime.push_back(num);
		}
		for (int i = 0; i < K; i++) {
			cin >> X >> Y;
			adj[X].push_back(Y);
			indegree[Y]++;
		}
		we_sort();
		for (int i = 0; i < 1001; i++) indegree[i] = 0;
		for (int i = 0; i < 1001; i++) adj[i].clear();
		vtime.clear();
	}
}
void we_sort() {
	int dp[1001] = { 0, };
	for (int i = 1; i <= N; i++) {
		dp[i] = vtime[i - 1];
	}
	int W=0;
	queue<int> q;
	vector<int> result;
	for (int i = 1; i <= N; i++)
		if (indegree[i] == 0) q.push(i);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		result.push_back(cur);
		for (int i = 0; i < adj[cur].size(); i++) {
			int nxt = adj[cur][i];
			indegree[nxt]--;
			if (indegree[nxt] == 0) q.push(nxt);
			dp[nxt] = max(dp[nxt], dp[cur] + vtime[nxt-1]);
		}
	}
	cin >> W;
	cout << dp[W] << "\n";
}
