#include <iostream>
#include <unordered_map>

using namespace std;
using ll = long long;
unordered_map<ll, ll> dp;
ll MOD = 1e9+7;

ll rec(ll sum) {
    if(sum == 0) return 1;
    if(sum < 0) return 0;
    if(dp.find(sum) != dp.end()) return dp[sum] % MOD;
    dp[sum] = 0;
    for(ll i=1; i<=6; i++) {
        dp[sum] += rec(sum - i) % MOD;
    }
    return dp[sum] % MOD;
}

int main() {
    ll n; cin >> n;
    cout << rec(n);
}
