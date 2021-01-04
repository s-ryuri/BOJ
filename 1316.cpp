#include <iostream>
using namespace std;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N,count = 0;
	string s;
	cin >> N;
	while (N--) {
		bool check[28] = { 0, };
		bool a = false;
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (!check[s[i] - 'a']) check[s[i] - 'a'] = true;
			else if (check[s[i] - 'a'] && s[i - 1] != s[i]) {
				a = true;
				break;
			}
		}
		if (!a)count++;
	}
	cout << count;
}
