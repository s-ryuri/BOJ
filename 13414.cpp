#include <iostream>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(nullptr);
	int K, L,num = 1,cnt = 0;
	string ID;
	map<string, int> ma;
	map<int,string> ma2;
	map<int, string>::iterator mi;
	cin >> K >> L;
	while (L--) {
		cin >> ID;
		ma[ID] = num++;
	}
	for (auto& x : ma)ma2[x.second] = x.first;
	mi = ma2.begin();
	while (K-- && cnt != ma2.size()) {
		cout << mi->second << "\n";
		mi++;
		cnt++;
	}
}
