#include <iostream>
#include <unordered_map>

using namespace std;
using ll = long long;

int main() {
    string s; cin >> s;
    ll size = s.size();

    unordered_map<char, ll> freq;
    ll countodd = 0;
    char charodd;
    for(char c : s) {
        if(freq.find(c) == freq.end()) freq[c] = 1;
        else freq[c]++;
    }

    for(auto i : freq) {
        if(i.second % 2 == 1) {
            countodd++;
            charodd = i.first;
        }
        if(countodd > 1) break;
    }
    if(countodd > 1) return printf("NO SOLUTION") * 0;

    string solution = "";
    // Adding odd element in center
    if(countodd == 1)
        for(ll i=0; i<freq[charodd]; i++) solution = solution + charodd;

    for(pair<char, ll> i : freq) {
        if(i.first != charodd) {
            for(ll j=0; j<i.second/2; j++) solution = i.first + solution + i.first;
        }
    }
    cout << solution;
    return 0;
}
