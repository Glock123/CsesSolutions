#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    /*
    ll n, x, y; cin >> n >> x;
    bool solved = false;
    unordered_map<ll, ll> store;
    ll i=1, pos1=-1, pos2=-1;
    while(i <= n) {
        cin >> y;
        if(!solved) {
            if(store.find(x-y) != store.end()) {
                solved = true;
                pos1 = store[x-y];
                pos2 = i;
            }
            else store[y] = i;
        }
        i++;
    }
    if(pos1 == -1) cout << "IMPOSSIBLE";
    else cout << pos1 << " " << pos2;
    */
    int n, x;
	cin >> n >> x;
	vector<pair<int, int>> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].first;
		arr[i].second = i + 1;
	}
	sort(arr.begin(), arr.end());
	int i = 0, j = n - 1;
	while (i < j)
	{
		if (arr[i].first + arr[j].first == x)
		{
			cout << arr[i].second << " " << arr[j].second;
			return 0;
		}
		if (arr[i].first + arr[j].first < x)
		{
			i++;
		}
		else
		{
			j--;
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}
