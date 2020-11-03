#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	int d[10001][3] = { 0, };
	int n;
	cin >> n;
	int* arr = new int[n+1];
	for (int i = 1; i <= n; i++) cin >> arr[i];
	d[1][1] = arr[1];
	d[2][2] = arr[1] + arr[2];
	for (int i = 2; i <= n; i++) {
		d[i][0] = max({ d[i - 1][0],d[i - 1][1],d[i - 1][2] });
		d[i][1] = d[i - 1][0]+ arr[i];
		d[i][2] = d[i - 1][1] + arr[i];
	}
	cout << max({d[n][0], d[n][1], d[n][2]});
}
