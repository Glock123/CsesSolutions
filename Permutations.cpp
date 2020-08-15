
#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll n; cin >> n;
    if(n == 1) return printf("1") * 0;
    if(n <= 3) return printf("NO SOLUTION") * 0;

    ll x = 2;
    while(x <= n) {
        cout << x << " ";
        x += 2;
    }
    x = 1;
    while(x <= n) {
        cout << x << " ";
        x += 2;
    }
    return 0;
}
