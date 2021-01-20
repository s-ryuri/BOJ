#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int G;
	cin >> G;
	vector<long long> v(G + 1); // 0~ G까지
	for (long long i = 0; i <= G; i++) {
		v[i] = i * i;
	}
	vector<int> vv;
	int s = 1, e = 1;
	while (1) {
		if (e == G + 1) break;
		else if (v[e] - v[s] > G) s++;
		else if (v[e] - v[s] < G) e++;
		else if (v[e] - v[s] == G) {
			vv.push_back(sqrt(v[e]));
			e++;
		}
	}
	if (!vv.size()) cout << -1;
	else for (auto& x : vv) cout << x << "\n";
}
