#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ll n, q; cin >> n >> q;
    ll a[n+1];
    vector<ll> prefixSum(n+1, 0);
    for(ll i=1; i<=n; i++) {
        cin >> a[i];
        prefixSum[i] = a[i] + prefixSum[i-1];
    }
    ll l, r;
    while(q--) {
        cin >> l >> r;
        cout << prefixSum[r] - prefixSum[l-1] << endl;
    }
    return 0;
}
