#include <iostream>
#include <unordered_map>

using namespace std;
unordered_map<int, int> dp;

int rec(int n) {
    if(n < 0) return 1e9;
    else if(n == 0) return 0;
    else if(dp.find(n) != dp.end()) return dp[n];

    int x = n;
    int m = 1e9;
    while(x) {
        if(x%10 == 0) {
            x /= 10; continue; }
        m = min(m, 1 + rec(n - x%10));
        x /= 10;
    }
    dp[n] = m;
    return m;
}

int main() {
    int n; cin >> n;
    cout << rec(n);
}
