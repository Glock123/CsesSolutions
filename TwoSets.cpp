#include <iostream>
#include <vector>

#define v vector
#define pb push_back

using namespace std;
using ll = long long;

typedef struct sset {
    v<ll> s;
    ll sum = 0;
} Set;

ll ifPossible(ll n, Set s1, Set s2) {
    if(n == 0) {
        if(s1.sum == s2.sum) {
            cout << "YES\n";
            cout << s1.s.size() << endl;
            for(ll i : s1.s) cout << i << " ";
            cout << endl << s2.s.size() << endl;
            for(ll i : s2.s) cout << i << " ";
            return 1;
        }
        else return 0;
    }

    s1.s.pb(n);
    s1.sum += n;
    ll a = ifPossible(n-1, s1, s2);
    s1.sum -= n;
    s1.s.pop_back();
    if(a == 1) return 1;

    s2.s.pb(n);
    s2.sum += n;
    ll b = ifPossible(n-1, s1, s2);
    s2.sum -= n;
    s2.s.pop_back();

    return max(a, b);
}

int main() {
    ll n; cin >> n;
    if( (n * (n+1)/2) % 2 == 1 ) return printf("NO") * 0;
    Set s1, s2;
    if(ifPossible(n, s1, s2) == 1) {}
    else cout << "NO";
    return 0;
}
