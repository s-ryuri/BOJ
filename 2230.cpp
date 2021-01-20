#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100002
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N,M;
	cin >> N >> M;
	vector<int> v(N);
	for (auto& x : v) cin >> x;
	sort(v.begin(), v.end());
	int s = 0, e = 0, result = 2e9 + 1;
	while (1) {
		if (e == N) break;
		else if (v[e] - v[s] <= M) {
			if(v[e] - v[s] == M) result = min(result, v[e] - v[s]);
			e++;
		}
		else {
			result = min(result, v[e] - v[s]);
			s++;
		}
	}
	cout << result;
}
