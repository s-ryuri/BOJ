#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N,tempa = -1,tempb = -1,result = 2e9 + 3;
	cin >> N;
	vector<int> v(N);
	for (auto& x : v) cin >> x;
	int s = 0, e = N - 1;
	sort(v.begin(), v.end());
	while (s < e) {
		if (v[s] + v[e] == 0) {
			if (v[s] >= v[e]) cout << v[e] << " " << v[s];
			else cout << v[s] << " " << v[e];
			return 0;
		}
		if (v[s] + v[e] > 0) {
			if (result > abs(v[s] + v[e])) {
				result = abs(v[e] + v[s]);
				tempa = v[e];
				tempb = v[s];
			}
			e--;
		}
		else if (v[s] + v[e] < 0) {
			if (result > abs(v[s] + v[e])) {
				result = abs(v[e] + v[s]);
				tempa = v[e];
				tempb = v[s];
			}
			s++;
		}
	}
	if(tempb >= tempa) cout << tempa << " " << tempb << "\n";
	else cout << tempb << " " << tempa << "\n";
}
