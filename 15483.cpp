#include<iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

const int MAX = 1e8;
int dp[1003][1003];

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0);
    string a, b;
    cin >> a;
    cin >> b;
    for (int i = 0; i < 1003; i++) {
        for (int j = 0; j < 1003; j++) {
            dp[i][j] = MAX;
        }
    }
    int asize = a.size(), bsize = b.size();
    
    for (int i = 0; i <= asize; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= bsize; j++) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= asize; i++) {
        for (int j = 1; j <= bsize; j++) {
            int alpha = 1;
            if (a[i-1] == b[j-1]) alpha = 0;          
            dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + alpha});
        }
    }
    
    /*for (int i = 0; i <= asize; i++) {
        for (int j = 0; j <= bsize; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }*/
    cout << dp[asize][bsize];
}
