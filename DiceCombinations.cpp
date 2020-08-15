#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

//ll a[7][10000000];

int main() {
    int n; cin >> n;
    int mod = 1e9+7;
    /*
    for(ll i=1; i<=n; i++) a[1][i] = 1;

    for(ll i=2; i<=6; i++) {
        for(ll j=1; j<=n; j++) {
            a[i][j] += a[i-1][j];
            if(j - i < 0) continue;
            else if(j - i == 0) a[i][j] += 1;
            else a[i][j] += a[i][j-i] * 2;
        }
    }

    for(ll i=0; i<=6; i++) {
        for(ll j=0; j<=n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << a[6][n];
    */
    vector<int> dp(n+1,0);
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 6 && i-j >= 0; j++) {
      (dp[i] += dp[i-j]) %= mod;
    }
  }
  cout << dp[n] << endl;

    return 0;
}
