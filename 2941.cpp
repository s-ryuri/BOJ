#include <iostream>
using namespace std;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	int cnt = 0;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'c') {
			if (s[i + 1] == '=') cnt++, i++;
			else if (s[i + 1] == '-') cnt++, i++;
			else cnt++;
		}
		else if (s[i] == 'd') {
			if (s[i + 1] == '-') cnt++, i++;
			else if (s[i + 1] == 'z') {
				if (s[i + 2] == '=')cnt++, i += 2;
				else cnt += 2, i++;
			}
			else cnt++;
		}
		else if (s[i] == 'l'|| s[i] == 'n') {
			if (s[i + 1] == 'j') cnt++, i++;
			else cnt++;
		}
		else if (s[i] == 's' || s[i] == 'z') {
			if (s[i + 1] == '=') cnt++, i++;
			else cnt++;
		}
		else cnt++;
	}
	cout << cnt;
}
