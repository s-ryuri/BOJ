#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define MOD 1000000007
#define minnum 1e9
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
	void init(int node, int s, int e) {
		int mid = (s + e) / 2;
		if (s == e) tree[node] = seq[s];
		else {
			init(node * 2, s, mid);
			init(node * 2 + 1, mid + 1, e);
			tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
		}
	}

	ll query(int node, int s, int e, ll i, ll j) {
		int mid = (s + e) / 2;
		if (i > e || j < s) return minnum;
		if (i <= s && e <= j) return tree[node];
		return min(query(node * 2, s, mid, i, j), query(node * 2 + 1, mid + 1, e, i, j));
	}
};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	ll a, b, c;
	cin >> N >> M;
	Segment se(N);
	for (int i = 1; i <= N; i++) cin >> se.seq[i];
	se.init(1, 1, N);
	while (M--) {
		cin >> a >> b;
		cout << se.query(1,1, N, a, b) << "\n";
	}
}
