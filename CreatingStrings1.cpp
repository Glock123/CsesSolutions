#include <iostream>
#include <string>
#include <set>

using namespace std;
set<string> ans;

void perm(int exclude, string s) {
    if(exclude <= 1) return;
    for(int i=0; i<s.size(); i++) {
        if(s.size()-i == exclude) continue;
        else {
            string si =s;
            char c = si[i];
            si[i] = si[s.size()-i];
            si[s.size()-i] = c;
            if(ans.find(si) != ans.end()) {
                ans.insert(si);
                perm(s.size()-i, si);
            }
        }
    }
}

void permutation(string prefix, string suffix) {
    if(suffix.size() == 0) ans.insert(prefix);
    for(int i=0; i<suffix.size(); i++) {
        permutation(prefix + suffix[i], suffix.substr(0, i) + suffix.substr(i+1));
    }
}

int main() {
    string s; cin >> s;
    //perm(10000, s);
    permutation("", s);
    cout << ans.size() << endl;
    for(string i: ans) cout << i << endl;
    return 0;
}
