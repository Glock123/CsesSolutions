#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

bool above500(ll n) {
    ll ans=0;
    for(ll i=1; i<=sqrt(n); i++) {
        if(n%i == 0) {
            if(n/i == i) ans++;
            else ans += 2;

            if(ans > 500) {
                cout << n;
                return true;
            }
        }
    }
    return false;
}

int main() {
    ll t; cin >> t;
    while(t--) {
        ll nextTraingleNumber = 0, i=1;
        bool ans = false;
        while(!ans) {
            nextTraingleNumber += i;
            i++;
            if(above500(nextTraingleNumber) == true) ans = true;
        }
    }
    return 0;
}
