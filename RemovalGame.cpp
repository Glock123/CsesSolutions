#include <iostream>
#include <vector>
#include <utility>

using namespace std;
using ll = long long;
int main() {
    ll n; cin >> n;
    ll a[n]; for(ll i=0; i<n; i++) cin >> a[i];

    vector<vector<pair<ll, ll>>> dp(n, vector<pair<ll, ll>>(n));

    for(ll interval=0; interval < n; interval++) {
        ll l=0, r = l+interval;
        while(r < n) {
            if(l == r) {
                dp[l][r] = {a[l], 0};
            }
            else {
                int x = a[l] + dp[l+1][r].second;
                int y = a[r] + dp[l][r-1].second;
                if(x > y) {
                    dp[l][r] = {x, dp[l+1][r].first};
                }
                else {
                    dp[l][r] = {y, dp[l][r-1].first};
                }
            }

            l++; r++;
        }

    }
    cout << dp[0][n-1].first;
    return 0;
}
