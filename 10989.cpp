#include <iostream>
using namespace std;
int main(void) {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	int arr[10001] = { 0, };
	int N,num;
	cin >> N;
	while (N--) {
		cin >> num;
		arr[num]++;
	}
	for (int i = 1; i <= 10000; i++)while (arr[i]--) cout << i << "\n";
}
