#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1003
int d[MAX];
int money[MAX];
int sorted[MAX];
int f(int);
int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    int N, P = 1;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> money[P++];
    d[0] = 0;
    d[1] = money[1];
    d[2] = min(money[2], 2 * money[1]);
    cout << f(N);
}

int f(int n) {
    if (n <= 2) return d[n];
    if (d[n] > 0) return d[n];
    else {
        for (int i = 0; i < n; i++)
            sorted[i] = f(n-i-1) + money[i+1];
        sort(sorted, sorted + n);
        d[n] = sorted[0];
    }
    return d[n];
}
