#include <iostream>

using namespace std;
using ll = long long;

int main() {
    int t; cin >> t;
    ll mod = 1000000007;
    while(t--) {
        ll n; cin >> n;
        ll dp[n+1];
        dp[1] = 1; dp[2] = 3;

        for(int i=3; i<=n; i++) {
            dp[n] = (2*dp[n-1] + 2*dp[n-2]) % mod;
        }
        cout << dp[n] << endl;
    }
    return 0;
}
