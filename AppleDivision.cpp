#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

int main() {
    ll n; cin >> n;
    ll p[n], totalSum = 0;
    for(ll i=0; i<n; i++) {
        cin >> p[i];
        totalSum += p[i];
    }
    ll ans = INT64_MAX;
    for(ll i=0; i < (1<<n); i++) {
        ll t1 = 0;
        for(int j=0; j<n; j++) {
            if(i>>j & 1) t1 += p[j];
        }
        ll t2 = totalSum - t1;
        ans = min(ans, abs(t2-t1));
    }
    cout << ans ;
    return 0;
}
