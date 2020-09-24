#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		string s;
		bool a = true;
		int cnt = 0;
		cin >> s;
		for (char ch : s) {
			if (ch == '(') cnt += 1;
			else cnt -= 1;
			if (cnt < 0) {
				cout << "NO" << "\n";
				a = false;
				break;
			}
		}
		if (a&&cnt == 0) cout << "YES"<<"\n";
		else if(a && cnt !=0) cout << "NO"<<"\n";
	}
}
