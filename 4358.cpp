#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(nullptr);
	map<string, double> ma;
	string name;
	double sum = 0,cnt = 0;
	while (getline(cin, name)) {
		ma[name]++;
		cnt++;
	}
	cout.setf(ios::fixed);
	cout.precision(4);
	for (auto& x : ma) cout << x.first << " " << (x.second / cnt) * 100 << "\n";
}

================================================================================
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(nullptr);
	map<string, double> ma;
	string name;
	double sum = 0;
	while (1) {
		getline(cin, name);
		if (cin.eof()) break;
		ma[name]++;
	}
	for (auto& x : ma) sum += x.second;
	for (auto x = ma.begin(); x != ma.end(); x++) {
		ma[x->first] = ((x->second) / sum) * 100;
	}
	cout.setf(ios::fixed);
	cout.precision(4);
	for (auto& x : ma) cout << x.first << " " << x.second << "\n";
}
