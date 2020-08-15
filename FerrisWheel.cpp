#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;
int main() {
    ll n, x; cin >> n >> x;
    ll a[n]; for(ll i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);
    ll i=0, j=n-1;
    ll c = 0;
    while(i <= j) {
        if(i == j) {
            if(a[i] <= x) {
                c++;
                break;
            }
        }
        else if(a[i] + a[j] <= x) {
            c++, i++, j--;
        }
        else {
            c++, j--;
        }
    }
    cout << c;
}
