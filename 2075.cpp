#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(nullptr);
	priority_queue<int,vector<int>,greater<int>> pq;
	int N,num;
	cin >> N;
	for (int i = 0; i < N * N; i++) {
		cin >> num;
		if (pq.size() < N) pq.push(num);
		else {
			pq.push(num);
			pq.pop();
		}
	}
	cout << pq.top();
}
