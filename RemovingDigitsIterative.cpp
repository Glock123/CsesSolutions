#include <iostream>
#include <vector>

using namespace std;

int main () {
    int n; cin >> n;
    vector<int> dp(n+1, 1e9);

    dp[0] = 0;
    for(int i=1; i<= n; i++) {
        int j = i;
        int m = 1e9;
        while(j) {
            if(i-j%10 >= 0)
                dp[i] = min(dp[i], dp[i-j%10] + 1);
            j /= 10;
        }
        //dp[i] += m+1;

    }
    cout << dp[n] << endl;
    return 0;
    //for(int i: dp) cout << i << " ";
}
