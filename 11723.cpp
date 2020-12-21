#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(nullptr);
	int M,x;
	int k = 0;
	string s;
	cin >> M;
	while (M--) {
		cin >> s;
		if (s == "add") {
			cin >> x;
			if(~(k & (1 <<x))) k |= (1 << x);
		}
		else if (s == "remove") {
			cin >> x;
			if (k & (1 << x)) k &= ~(1 << x);
		}
		else if (s == "check") {
			cin >> x;
			if (k & (1 << x)) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (s == "toggle") {
			cin >> x;
			if (k & (1 << x)) k &= ~(1 << x);
			else k |= (1 << x);
		}
		else if (s == "all")k |= (1 << 21) - 1;
		else k = 0;
	}
}
