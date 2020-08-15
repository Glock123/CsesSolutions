#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

int main() {
    ll n, m, k; cin >> n >> m >> k;
    ll a[n];
    vector<ll> b(m);
    for(ll i=0; i<n; i++) cin >> a[i];
    for(ll i=0; i<m; i++) cin >> b[i];

    sort(b.begin(), b.end());

    sort(a, a+n);
    ll countAssigned = 0, i=0, j=0;
    while(i < n && j < m) {
        if(abs(a[i]-b[j]) <= k) {
            countAssigned++; i++; j++;
        }
        else if(a[i] > b[j]) j++;
        else i++;
    }
    cout << countAssigned;
}
