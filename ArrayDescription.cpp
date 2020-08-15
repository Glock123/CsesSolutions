#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, MOD=1e9+7; cin >> n >> m;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];

    vector<vector<int>> dp(n, vector<int>(m, 0));
    if(a[0] == 0) for(int i=0; i<m; i++) dp[0][i] = 1;
    else dp[0][a[0]-1] = 1;

    for(int i=1; i<n; i++) {
        if(a[i] > 0) {
            (dp[i][a[i]-1] += dp[i-1][a[i]-1]) %= MOD;
            if(a[i]-1-1 >= 0) (dp[i][a[i]-1] += dp[i-1][a[i]-2]) %= MOD;
            if(a[i]-1+1 < m) (dp[i][a[i]-1] += dp[i-1][a[i]]) %= MOD;
        }
        else {
            for(int j=0; j<m; j++) {
                (dp[i][j] += dp[i-1][j]) %= MOD;
                if(j-1 >= 0) (dp[i][j] += dp[i-1][j-1]) %= MOD;
                if(j+1 < m) (dp[i][j] += dp[i-1][j+1]) %= MOD;
            }
        }


    }
    int numWays = 0;
    for(int i=0; i<m; i++) (numWays += dp[n-1][i]) %= MOD;
    cout << numWays ;
    /*
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) cout << dp[i][j] << " ";
        cout << endl;
    }
    */
    return 0;
}
