#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(nullptr);
	int N;
	cin >> N;
	int* arr = new int[N];
	int* d = new int[N];
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < N; i++) {
		d[i] = 1;
		for (int j = 0; j < i; j++) {
			if (d[i] < d[j] + 1 && arr[j] < arr[i]) d[i] = d[j] + 1;
		}
	}
	sort(d, d + N);
	cout << d[N - 1];
	delete[] arr;
	delete[] d;
}
