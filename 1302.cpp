#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(nullptr);
	map<string, int> ma;
	int maxnum = -1;
	int N;
	string name;
	cin >> N;
	while (N--) {
		cin >> name;
		ma[name]++;
	}
	for (auto& x : ma) maxnum = max(maxnum, x.second);
	for (auto& x : ma) {
		if (x.second == maxnum) {
			cout << x.first;
			return 0;
		}
	}
}
