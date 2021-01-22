#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N,sum,result = -1;
	cin >> N;
	vector<int> v(N);
	for (auto& x : v) cin >> x;
	sort(v.begin(), v.end());
	do {
		sum = 0;
		for (int i = 0; i <= N -2; i++) {
			sum += abs(v[i] - v[i + 1]);
		}
		result = max(result, sum);
	} while (next_permutation(v.begin(), v.end()));
	cout << result;
}
