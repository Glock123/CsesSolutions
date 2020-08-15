#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
using ll = long long;

//unordered_map<ll, ll> dp;
//vector<ll> a;
/*
ll rec(ll sum, ll numCoins) {
    if(sum < 0) return INT64_MAX;
    if(sum == 0) return numCoins;
    if(dp.find(sum) != dp.end()) return dp[sum];
    ll minimalCost = INT64_MAX;
    for(const ll i: a) {
        minimalCost = min(minimalCost, rec(sum-i, numCoins + 1));
    }
    dp[sum] =  minimalCost;
    cout << sum << "-" << minimalCost << "  ";
    return minimalCost;
}
*/
int main() {
    ll n, x, t; cin >> n >> x;
    ll a[n];
    for(ll i=0; i<n; i++)
        cin >> a[i];

    //cout << rec(x, 0);
    //ll dp[n+1][x+1] = {0LL};
    vector<vector<ll> >dp(n, vector<ll>(x+1, 0));
    ll c = 1;

    for(ll i=1; i<=x; i++) {
        if(i % a[0] == 0) dp[0][i] = c;
        c++;
    }

    for(ll i=1; i<n; i++) {
        for(ll j=1; j<=x; j++) {
            ll m, n;
            if(i-1 < 0) {
                if(j-a[i] < 0) {}
                else dp[i][j] = dp[i][j-a[i]] + 1;
                continue;
            }
            if(j - a[i] >= 0) dp[i][j] = min(dp[i-1][j], dp[i][j - a[i]] + 1);
            else dp[i][j] = dp[i-1][j];
        }
    }
    /*
    for(ll i=0; i<n; i++) {
        for(ll j=0; j<=x; j++) cout << dp[i][j] << " ";
        cout << endl;
    }
    */
    if(dp[n-1][x] == 0) cout << -1;
    else cout << dp[n-1][x];
    return 0;
}
