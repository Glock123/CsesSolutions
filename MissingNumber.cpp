#include <iostream>

using namespace std;
using ll = long long;

ll a[200000] = {0LL};

int main() {
    ll n, x; cin >> n;

    for(ll i=0; i<n-1; i++) {
        cin >> x;
        ++a[x];
    }
    for(ll i=1; i<n+1; i++) {
        if(a[i] == 0)
            return printf("%d", i) * 0;
    }
}
