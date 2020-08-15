#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll n, x; cin >> n;
    map<ll, ll> m;
    ll q = n;
    while(n--) {
        cin >> x;
        if(m.find(x) == m.end()) m[x] = 1;
        else m[x]++;
    }

    typedef function<bool(pair<ll, ll>, pair<ll, ll>)> Comparator;

    Comparator comp = [](pair<ll, ll> elem1, pair<ll, ll> elem2) {
        return elem1.second > elem2.second;
    };


    std::sort(m.begin(), m.end(), comp);

    ll s = m.size(), i=1;
    ll maxFreq = INT64_MIN, maxEle;
    for(const auto it: m) {
        if(it.second > maxFreq) {
            maxFreq = it.second;
            maxEle = it.first;
        }
        else if(it.second == maxFreq) {
            if(i < s/2) maxEle = it.first;
        }
        else {}
        i++;
    }

    ll cost = 0;
    for(const auto i : m) {
        if(i.first == maxEle) continue;
        cost += abs(maxEle - i.first) * i.second;
    }
    std::cout << cost;
    return 0;
}
