
#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll n; cin >> n;
    if(n == 1) return (printf("1")) * 0;
    while(n != 1) {
        cout << n << " ";
        if(n%2) n = 3 * n + 1;
        else n /= 2;
    }
    cout << 1;
    return 0;
}
