#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(nullptr);
	int A, B,num;
	unordered_set<int> a,b;
	unordered_set<int>::iterator si,temp;
	cin >> A >> B;
	while (A--) {
		cin >> num;
		a.insert(num);
	}
	while (B--) {
		cin >> num;
		b.insert(num);
	}
	for (si = a.begin(); si != a.end();) {
		if (b.count(*si)) {
			temp = si;
			temp++;
			b.erase(*si);
			a.erase(*si);
			si = temp;
		}
		else si++;
	}
	cout << a.size() + b.size();
}
