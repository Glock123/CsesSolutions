#include <iostream>
#include <string>
using namespace std;

string findString(int k) {
    int numCompleteRepetitions = k/26;

    int numOverlaps = k%26;
    string sol = "";
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    for(int i=1; i<=26; i++) {
        for(int j=0; j<numCompleteRepetitions; j++) sol = sol + alpha[i-1];
        if(i <= numOverlaps) sol = sol + alpha[i-1];
    }
    return sol;
}

int main() {
    int n, k; cin >> n >> k;

    string kString = findString(k);
    for(int i=0; i<n; ) {
        cout << kString;
        i += k;
    }
    return 0;
}
