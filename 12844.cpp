#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;

char buf[1 << 17];
inline char read()
{
	static int idx = 1 << 17;
	if (idx == 1 << 17)
	{
		fread(buf, 1, 1 << 17, stdin);
		idx = 0;
	}
	return buf[idx++];
}
inline ll readInt()
{
	ll sum = 0;
	bool sig = 1;
	char now = read();

	while (now == 10 || now == 32) now = read();
	if (now == '-') sig = 0, now = read();
	while (now >= 48 && now <= 57)
	{
		sum = sum * 10 + now - 48;
		now = read();
	}

	return sig ? sum : -sum;
}

struct Segment {
	vector<ll> tree; //segment 트리를 만들때 사용하는 배열
	vector<ll> seq; //처음에 숫자를 입력 받는 배열
	vector<ll> lazy; //lazy를 담는 배열
	Segment(ll n) { //tree size를 정해주는 생성자 보통 4 * N으로 해도 되긴하다.
		seq.resize(n + 1);
		ll log = ceil(log2(n));
		ll t = (1LL << (log + 1));
		tree.resize(t);
		lazy.resize(t);
	}

	void init(ll node, ll start, ll end) {
		ll mid = (start + end) / 2;
		if (start == end) tree[node] = seq[start];
		else {
			init(node * 2, start, mid);
			init(node * 2 + 1, mid + 1, end);
			tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
		}
	}

	ll query(ll node, ll start, ll end, ll i, ll j) {
		ll mid = (start + end) / 2;
		if (lazy[node] != 0) {
			tree[node] ^= ((end - start + 1)%2) * lazy[node];
			if (start != end) {
				lazy[node * 2] ^= lazy[node];
				lazy[node * 2 + 1] ^= lazy[node];
			}
			lazy[node] = 0;
		}
		if (i > end || j < start) return 0;
		if (i <= start && end <= j) return tree[node];
		return query(node * 2, start, mid, i, j) ^ query(node * 2 + 1, mid + 1, end, i, j);
	}

	void update(ll node, ll start, ll end, ll i, ll j, ll diff) {
		ll mid = (start + end) / 2;
		if (lazy[node] != 0) {
			tree[node] ^= ((end - start + 1)%2) * lazy[node];
			if (start != end) {
				lazy[node * 2] ^= lazy[node];
				lazy[node * 2 + 1] ^= lazy[node];
			}
			lazy[node] = 0;
		}

		if (j < start || i > end) return;
		if (i <= start && end <= j) {
			tree[node] ^= ((end - start + 1) % 2) * diff;
			if (start != end) {
				lazy[node * 2] ^= diff;
				lazy[node * 2 + 1] ^= diff;
			}
			return;
		}
		update(node * 2, start, mid, i, j, diff);
		update(node * 2 + 1, mid + 1, end, i, j, diff);
		tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
	}
};

int main() {
	ll N, M,a,b,c,d;
	N = readInt();
	Segment se(N);
	for (int i = 1; i <= N; i++) se.seq[i] = readInt();
	se.init(1, 1, N);
	M = readInt();
	while (M--) {
		a = readInt();
		if (a == 1) {
			b = readInt();
			c = readInt();
			d = readInt();
			if (b > c) swap(b, c);
			se.update(1, 1, N, b + 1, c + 1, d);
		}
		else {
			b = readInt();
			c = readInt();
			if (b > c) swap(b, c);
			cout << se.query(1, 1, N, b + 1, c + 1) << "\n";
		}
	}
}
