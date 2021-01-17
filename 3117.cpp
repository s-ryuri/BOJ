#include <iostream>
#include <vector>
using namespace std;
#define MAX 100001
#define PMAX 31

int arr[MAX][PMAX] = { 0, };
int a[MAX] = { 0, };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, K, M;
	cin >> N >> K >> M;
	//N명의 학생, 남은 M분, K개의 동영상
	

	for (int i = 1; i <= N; i++) cin >> a[i];
	for (int i = 1; i <= K; i++) cin >> arr[i][0];
	for (int j = 1; j < PMAX; j++) {
		for (int i = 1; i <= K; i++)
			arr[i][j] = arr[arr[i][j - 1]][j - 1];
	}
    for (int i = 1; i <= N; i++) {
		int s = a[i], temp = M - 1;
        for (int j = PMAX - 1; j >= 0; j--) {
            if (temp >= (1 << j)) {
                temp -= (1 << j);
                s = arr[s][j];
            }
        }
        cout << s << ' ';
    }
}
