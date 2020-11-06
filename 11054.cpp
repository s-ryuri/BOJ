#include <iostream>
using namespace std;
#define MAX 1001
int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	int arr[MAX] = { 0, };
	int d[MAX] = { 0, };
	int d2[MAX];
	int N, k = 1;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	//가장 긴 증가하는 부분 수열
	for (int i = 1; i <= N; i++) {
		d[i] = 1;
		fill(d2, d2 + N + 1, 1);
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j] && d[i] < d[j] + 1)
				d[i] = d[j] + 1;
		}
		int temp = i;
		d2[temp] = d[temp];
		for (int p = i; p <= N; p++) {
			for (int j = temp; j <= p; j++) {
				if (arr[p] < arr[j] && d2[p] < d2[j] + 1)
					d2[p] = d2[j] + 1;
				k = max(d2[p], k);
			}
		}
	}
	cout << k;
}
