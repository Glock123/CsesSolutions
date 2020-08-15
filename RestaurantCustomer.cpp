#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define pb push_back

using namespace std;
using ll = long long;

int main() {
    int n, a, b; cin >> n;
    vector<pair<ll, ll>> cust;
    while(n--) {
        cin >> a >> b;
        cust.pb( {a, 1} );
        cust.pb( {b, -1} );
    }
    sort(cust.begin(), cust.end());

    ll currentCustomer = 0, maxCustomer = INT64_MIN;
    for(auto i: cust) {
        if(i.second == 1) currentCustomer++;
        else currentCustomer--;
        maxCustomer = max(maxCustomer, currentCustomer);
    }
    cout << maxCustomer;
}
