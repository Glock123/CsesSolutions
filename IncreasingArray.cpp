#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll n; cin >> n;
    ll a[n]; for(ll i=0; i<n; i++) cin >> a[i];
    ll ops = 0;
    for(ll i=1; i<n; i++) {
        if(a[i] < a[i-1]) {
            ops += a[i-1] - a[i];
            a[i] = a[i-1];
        }
    }
    cout << ops;
}
