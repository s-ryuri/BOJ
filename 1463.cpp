#include <iostream>
#include<algorithm>
#define NUM 1000001
using namespace std;

int memo[NUM];

int makeOne(int num);

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	int N;
	fill(memo, memo + NUM, -1);
	cin >> N;
	cout << makeOne(N);
}
int makeOne(int num) {
	if (num == 1) return 0;
	if (memo[num] != -1) return memo[num];

	int criteria = makeOne(num - 1) + 1;
	if (num % 3 == 0) criteria = min(criteria, makeOne(num / 3) + 1);
	if (num % 2 == 0) criteria = min(criteria, makeOne(num / 2) + 1);
	memo[num] = criteria;
	return criteria;
}

//kks227님의 블로그에서 배운 코드입니다.
