#include <iostream>
#include <vector>

using namespace std;

int main() {
    int MOD = 1e9+7;
    int n, target; cin >> n >> target;
    int a[n]; for(int i=0; i<n; i++) cin >> a[i];
    //int dp[n+1][target+1] = {0};
    vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
    for(int i=0; i<=n; i++) dp[i][0] = 1;

    for(int i=1; i<=n; i++) {
        for(int j=1; j <= target; j++) {
            (dp[i][j] += dp[i-1][j]) %= MOD;
            if(j - a[i-1] >= 0) (dp[i][j] += dp[i][j - a[i-1]]) %= MOD;
        }
    }
    cout << dp[n][target];
    return 0;
}
