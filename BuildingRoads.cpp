#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
unordered_map<int, vector<int>> g;

void dfs(int curr, vector<bool>& visited) {
    visited[curr] = true;
    for(auto i: g[curr]) {
        if(visited[i] == false) dfs(i, visited);
    }
}

int main() {
    int n, m, x, y;
    cin >> n >> m;
    for(int i=0 ;i<m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<bool> visited(n+1, false);
    vector<int> ans;
    for(int i=1; i<=n; i++) {
        if(visited[i] == false) {
            ans.push_back(i);
            dfs(i, visited);
        }
    }
    cout << ((ans.size()-1 < 0)? 0: ans.size()-1) << endl;
    for(int i=0; i<ans.size()-1; i++) {
        cout << ans[i] << " " << ans[i+1] << endl;
    }
    return 0;
}
