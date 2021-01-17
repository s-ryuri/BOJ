#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MOD 1000000007
using namespace std;

using ll = long long;

struct Segment {
	vector<ll> tree;
	vector<ll> seq;
	Segment(int n) {
		seq.resize(n + 1);
		int log = ceil(log2(n));
		ll t = (1LL << (log + 1));
		tree.resize(t);
	}

	ll init(int node, int s, int e) {
		if (s == e) return tree[node] = seq[s];
		int mid = (s + e) / 2;
		return tree[node] = init(node * 2, s, mid) % MOD * init(node * 2 + 1, mid + 1, e) % MOD;
	}
	ll query(int node, int s, int e, int i, int j) {
		if (e < i || s > j) return 1;
		if (i <= s && e <= j) return tree[node];
		int mid = (s + e) / 2;
		return query(node * 2, s, mid, i, j) % MOD * query(node * 2 + 1, mid + 1, e, i, j) % MOD;
	}

	ll update(int node, int s, int e, int i, int u) {
		int mid = (s + e) / 2;
		if (i < s || i > e) return tree[node];
		if (s == e) return tree[node] = u;
		return tree[node] = update(node * 2, s, mid, i, u) % MOD  * update(node * 2 + 1, mid + 1, e, i, u) % MOD;
	}
};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M,K,a, b, c;
	cin >> N >> M >> K;
	Segment se(N);
	for (int i = 1; i <= N; i++) cin >> se.seq[i];
	
	se.init(1, 1, N);
	int aa = M + K;
	while (aa--) {
		cin >> a >> b >> c;
		if (a == 1) se.update(1, 1, N, b, c);
		else cout << se.query(1, 1, N, b, c) % MOD << "\n";
	}
	
}
