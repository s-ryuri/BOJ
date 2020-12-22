#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(nullptr);
	int N, M,cnt = 1;// 도감수록 포켓몬
	string name;
	unordered_map<string, string> um;
	unordered_map<string, string> um2;
	cin >> N >> M;
	while (N--) {
		cin >> name;
		um[name] = to_string(cnt);
		um2[to_string(cnt)] = name;
		cnt++;
	}
	while (M--) {
		cin >> name;
		if (um.count(name)) cout << um[name] << "\n";
		else if (um2.count(name)) cout << um2[name] << "\n";
	}
}
