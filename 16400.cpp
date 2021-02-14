#include <iostream>
#include <vector>
#define MAX 40002
using namespace std;

const int MOD = 123456789;
long long dp[MAX] = { 1,};
bool check[MAX] = { 1,1, };
vector<int> prime;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 2; i * i <= MAX; i++)
		if (!check[i]) for (int j = i * i; j <= MAX; j += i) check[j] = 1;

	for (int i = 2; i <= MAX; i++) if (!check[i]) prime.push_back(i);
	int N;
	cin >> N;
	int vsize = prime.size();
	for (int i = 0; i < vsize; i++) {
		for (int j = prime[i]; j <= N; j++) {
			dp[j] += (dp[j - prime[i]]) % MOD;
			dp[j] %= MOD;
		}
	}
	cout << dp[N];
}
