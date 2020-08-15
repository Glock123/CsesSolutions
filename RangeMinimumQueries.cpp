#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
using ll = long long;
void constructSegmentTree(ll* a, vector<ll>& segment_tree, ll lo, ll hi, ll pos) {
    if(lo == hi) {
        segment_tree[pos] = a[lo];
        return;
    }
    ll mid = (hi+lo)/2;
    constructSegmentTree(a, segment_tree, lo, mid, 2*pos + 1);
    constructSegmentTree(a, segment_tree, mid+1, hi, 2*pos + 2);
    segment_tree[pos] = min(segment_tree[2*pos + 1], segment_tree[2*pos + 2]);
    return ;
}

ll query(vector<ll>& segment_tree, ll lo, ll hi, ll qlo, ll qhi, ll pos) {
    if(qlo <= lo && qhi >= hi) return segment_tree[pos];
    else if(qlo > hi || qhi < lo) return 1e9;
    ll mid = (lo + hi)/2;
    return min(query(segment_tree, lo, mid, qlo, qhi, 2*pos+1),
               query(segment_tree, mid+1, hi, qlo, qhi, 2*pos+2));
}

int main() {
    ll n, q; cin >> n >> q;
    ll a[n], l, r;
    for(int i=0; i<n; i++) cin >> a[i];
    int size_of_segment_tree = pow(2, ceil(log2(n))) * 2 - 1;
    vector<ll> segment_tree(size_of_segment_tree, 1e6);
    constructSegmentTree(a, segment_tree, 0, n-1, 0);
    //for(int i: segment_tree) cout << i << " ";

    while(q--) {
        cin >> l >> r;
        cout << query(segment_tree, 0, n-1, --l, --r, 0) << endl;
    }

    return 0;
}
