#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 1001
using namespace std;

int w[MAX], v[MAX];
int N, K;
int dp[MAX][100001];
int dfs(int idx, int weight) {
	int n1 = 0, n2;
	if (dp[idx][weight] > 0) return dp[idx][weight];
	if (idx == K) return 0;
	if (weight + w[idx] <= N) n1 = v[idx] + dfs(idx + 1, weight + w[idx]);
	n2 = dfs(idx + 1, weight);
	return dp[idx][weight] = max(n1, n2);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < K; i++) cin >> v[i] >> w[i];
	cout << dfs(0, 0);
}
