#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
int main() {
    ll t; cin >> t;
    while(t--) {
        ll y, ans, x; cin >> y >> x;
        if(y > x) {
            ll maxEle = y*y;
            ans = maxEle - x + 1;
        }
        else {
            ll maxEle = x * x;
            ans = maxEle - y + 1;
        }
        cout << ans << "\n";
    }
    return 0;
}
