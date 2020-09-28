#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	int N, B;
	string s = "";
	cin >> N >> B;
	while (N >= 1) {
		if (N % B >= 10) s = (char)(N%B - 10 + 'A') + s;
		else s = to_string(N % B) + s;
		N /= B;
	}
	cout << s;
}
