/* 0-1 Knapsack Problem */
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x; cin >> n >> x;
    int cost[n], weight[n]; // weight represent pages
    for(int i=0; i<n; i++) cin >> cost[i];
    for(int i=0; i<n; i++) cin >> weight[i];

    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=x; j++) {
            /*
            if(j%cost[i-1] == 0 && j/cost[i-1] > 1) dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            else if(j - cost[i-1] >= 0) dp[i][j] = max(dp[i-1][j], weight[i-1] + dp[i][j - cost[i-1]]);
            else dp[i][j] = dp[i-1][j];
            */
            if(j-cost[i-1] >= 0) dp[i][j] = max(dp[i-1][j], weight[i-1] + dp[i-1][j-cost[i-1]]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][x] << endl;
    /*
    for(int i=0; i<n+1; i++) {
        for(int j=0; j<=x; j++) cout << dp[i][j] <<  " ";
        cout << endl;
    }
    */
    return 0;
}

