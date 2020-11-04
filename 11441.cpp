#include <iostream>
#include<algorithm>
using namespace std;
#define MAX 100001
int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	int N, Q,num1,num2;
	cin >> N;
	int arr[MAX] = { 0, };
	int sum[MAX] = { 0, };
	for (int i = 1; i <= N; i++) cin >> arr[i];
	cin >> Q;
	for (int i = 1; i <= N; i++) {
		if (i == 1) sum[i] = arr[i];
		else sum[i] = sum[i - 1] + arr[i];
	}
	while (Q--) {
		cin >> num1 >> num2;
		cout << sum[num2] - sum[num1 - 1] << "\n";
	}
}
