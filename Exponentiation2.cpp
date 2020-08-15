#include <iostream>
#define MOD 1000000007

using namespace std;
using ll = long long;

int main() {
    ll t; cin >> t;
    while(t--) {
        ll a, b, c; cin >> a >> b >> c;
        ll ans = 1, ans1 = 1;
        while(c) {
            if(c%2 == 1)
                ans = (ans * b) % MOD;
            b = (b*b) % MOD;
            c /= 2;
        }

        while(ans) {
            if(ans%2 == 1)
                ans1 = (ans1 * a) % MOD;
            a  = (a*a)% MOD;
            ans /= 2;
        }
        cout << ans1 << endl;
    }
}
