#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];

    vector<int> dp(target + 1, 1e9);
    dp[0] = 0;
    for(int i=1; i<=target; i++)
        for(int j=0; j<n; j++)
            if(i - a[j] >= 0) dp[i] = min(dp[i], dp[i-a[j]]+1);

    if(dp[target] == 1e9) return printf("-1")*0;
    else cout << dp[target];
    return 0;
}
