#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(nullptr);
	int T, n;
	string a, b;
	cin >> T;
	while (T--) {
		cin >> n;
		int count = 1;
		map<string, int> ma;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			ma[b]++;
		}
		for (auto mi = ma.begin(); mi != ma.end(); mi++) {
			count *= (mi->second + 1);
		}
		cout << count - 1 << "\n";
	}
}
