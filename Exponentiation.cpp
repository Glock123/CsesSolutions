#include <iostream>
#define MOD 1000000007

using namespace std;
using ll = long long;

int main() {
    ll t; cin >> t;
    while(t--) {
        ll a, b; cin >> a >> b;
        ll ans = 1;
        while(b) {
            if(b%2 == 1)
                ans *= a, ans = ans % MOD;
            a *= a;
            a = a % MOD;
            b /= 2;
        }
        cout << ans%MOD << endl;
    }
}
