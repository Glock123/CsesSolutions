#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b; cin >> a >> b;

    vector<vector<int>> dp(a+1, vector<int>(b+1, 1e9));
    dp[1][1] = 0; // a rectagle with 0 height and 0 width will require 0 cuts

    for(int i=1; i<=a; i++) {
        for(int j=1; j<=b; j++) {
            if(i == j) dp[i][j] = 0; // Already a square
            else {
                for(int m=1; m<i; m++)
                    dp[i][j] = min(dp[i][j], dp[m][j] + dp[i-m][j] + 1); // +1 for the cut we made now

                for(int m=1; m<j; m++)
                    dp[i][j] = min(dp[i][j], dp[i][m] + dp[i][j-m] + 1);

            }

        }
    }
    cout << dp[a][b];
    return 0;
}
