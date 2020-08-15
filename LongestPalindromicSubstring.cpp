#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s; cin >> s;
    int n = s.size();
    vector<vector<int>>dp(n, vector<int>(n, 0));

    for(int i=0; i<n; i++) dp[i][i] = 1;

    for(int i=1; i<n; i++) {
        for(int j=i-1; j>=0; j--) {
            if(s[i] == s[j]) dp[j][i] = 2 + dp[j+1][i-1];
            else dp[j][i] = max(dp[j+1][i], dp[j][i-1]);
        }
    }

    cout << dp[0][n-1];
    return 0;
}
