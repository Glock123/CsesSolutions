#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll n; cin >> n;
    for(int i=1; i<=n; i++) {
        if(i > 1) {
            ll ans = i*i * (i*i-1)/2 - 4 * (i-1) * (i-2);
            cout << ans << endl;
        }
        else cout << 0 << endl;
    }
    return 0;
}
