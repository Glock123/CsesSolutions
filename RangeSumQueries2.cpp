/* Square Root Decomposition */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

typedef struct S {
    vector<ll> arr;
    ll sum = 0;
} s;


int main() {
    ll n, q; cin >> n >> q;
    ll m[n];
    for(ll i=0; i<n; i++) cin >> m[i];
    ll srd_size = sqrt(n);
    ll x = ceil(n/srd_size);
    s S[x];

    for(ll i=0; i<n; i++) {
        ll curr_block = i / srd_size;
        S[curr_block].arr.push_back(m[i]);
        S[curr_block].sum += m[i];
    }
    ll type, a, b;
    while(q--) {
        cin >> type >> a >> b; a--;
        switch(type) {
            case 1:
                ll curr_block = a / srd_size;
                ll pos = a % srd_size;

                S[curr_block].sum  = S[curr_block].sum - S[curr_block].arr[pos] + b;
                S[curr_block].arr[pos] = b;

                break;

            case 2:
                b--;
                ll sumAll = 0;
                //Excluding values from first block
                sumAll += S[a/srd_size].sum;
                for(int i=0; i<srd_size; i++) {
                    if(i < a % srd_size) sumAll -= S[a/srd_size].arr[i];
                    else break;
                }

                //Adding all the complete block's sums
                for(int i = a/srd_size+1; i < b/srd_size; i++) sumAll += S[i].sum;

                //Excluding elements from the last block
                sumAll += S[b/srd_size].sum;
                for(int i=S[b/srd_size].arr.size()-1; i>=0; i--) {
                    if(i > a % srd_size) sumAll -= S[b/srd_size].arr[i];
                    else break;
                }
                cout << sumAll << endl;
                break;
        }
    }

    return 0;
}
