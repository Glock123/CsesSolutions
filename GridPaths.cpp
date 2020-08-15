#include <iostream>
#include <vector>

using namespace std;

int main() {
    int MOD = 1e9+7;
    int n;
    cin >> n;
    //char a[n][n];
    vector<vector<char>> a(n, vector<char>(n));
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> a[i][j];

    vector<vector<int>> dp(n, vector<int>(n, 0));
    if(a[0][0] == '*') dp[0][0] = 0;
    else dp[0][0] = 1;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            //cout << "HI ";
            if(a[i][j] == '*') continue;
            else {
                if(i-1 >= 0) dp[i][j] += dp[i-1][j] % MOD;
                if(j-1 >= 0) dp[i][j] += dp[i][j-1] % MOD;
                //dp[i][j] += (dp[i-1][j] + dp[i][j-1]) % MOD;
            }
        }
    }
    cout << dp[n-1][n-1] % MOD;
    return 0;
}
