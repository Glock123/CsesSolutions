#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n; cin >> n;
    int sum=0;
    int a[n]; for(int i=0; i<n; i++) {
                cin >> a[i];
                sum += a[i];
              }

    vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
    vector<int> possible_sum;
    int numPossible = 0;
    for(int i=1; i<=n; i++) {
        if(dp[i-1][a[i-1]] > 0) {
            dp[i][a[i-1]] = dp[i-1][a[i-1]];
        }
        else {
            dp[i][a[i-1]] = ++numPossible;
            possible_sum.push_back(a[i-1]);
        }
        for(int j=0; j<=sum; j++) {
            if(dp[i-1][j] > 0) dp[i][j] = dp[i-1][j];
            else if(j - a[i-1] >= 0 && dp[i][j] == 0) {
                if(dp[i-1][j - a[i-1]] > 0) {
                    dp[i][j] = ++ numPossible;
                    possible_sum.push_back(j);
                }
            }
        }
    }
    sort(possible_sum.begin(), possible_sum.end());
    cout << numPossible << endl;
    for(int i: possible_sum) cout << i << " ";
    /*
    cout << endl;
    for(auto i: dp) {
        for(auto j: i) cout << j << " ";
        cout << endl;
    }
    */
}
