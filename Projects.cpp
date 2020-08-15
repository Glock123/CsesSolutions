#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
    int n, x, y, z; cin >> n;
    vector<tuple<int, int, int>> a(n);
    for(int i=0; i<n; i++) {
        cin >> x >> y >> z;
        a[i] = {x, y, z};
    }

    sort(a.begin(), a.end());
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i=0; i<n; i++) {
        dp[i][i] = get<2>(a[i]);
    }

    for(int j=1; j<n; j++) {
        for(int i=j-1; i>=0; i--) {
            int temp = 0;
            if(get<1>(a[i]) < get<0>(a[j])) temp = get<2>(a[i]) + get<2>(a[j]);
            dp[i][j] = max({dp[i+1][j], dp[i][j-1], temp});
        }
    }
    cout << dp[0][n-1];
    return 0;
}
