#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string s; cin >> s;
    ll maxGlobal = INT64_MIN, maxLocal = 1;

    if(s.size() == 1) return printf("1") * 0;

    for(ll i=0; i<s.size()-1; i++) {
        if(s[i] == s[i+1]) maxLocal++;
        else {
            maxGlobal = max(maxGlobal, maxLocal);
            maxLocal = 1;

        }
    }
    cout << max(maxGlobal, maxLocal);
}
