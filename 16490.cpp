#include <iostream>
#include <cmath>
using namespace std;
int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	double a, t;
	cin >> a >> t;
	cout << round(a * a - t * t);
}
