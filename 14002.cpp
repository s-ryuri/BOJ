#include <iostream>
#include <algorithm>
using namespace std;

int* arr;
int* dist;
int* cmp;
int* distcopy;
void result(int n);

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	int N;
	int max = 0;
	cin >> N;
	arr = new int[N]; // 숫자를 담을 배열
	dist = new int[N]; // 길이를 담을 배열
	distcopy = new int[N]; // 길이를 담을 배열
	cmp = new int[N]; // 수열을 찾을 수 있게 만든 배열
	fill(cmp, cmp + N, -1);

	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < N; i++) {
		dist[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dist[i] < dist[j] + 1) {
				dist[i] = dist[j] + 1;
				cmp[i] = j;
			}
		}
	}
	copy(dist, dist + N, distcopy);
	sort(dist, dist + N);
	cout << dist[N - 1] << "\n";
	for (int i = 0; i < N; i++) {
		if (distcopy[i] == dist[N - 1]) max = i;
	}
	result(max);
	delete[] arr;
	delete[] dist;
	delete[] distcopy;
	delete[] cmp;
}

void result(int n) {
	if (n == -1) return;
	result(cmp[n]);
	cout << arr[n] << ' ';
}
