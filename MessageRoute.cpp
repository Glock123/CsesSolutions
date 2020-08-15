#include <iostream>
#include <unordered_map>
#include <vector>
#define pb push_back

using namespace std;

unordered_map<int, vector<int>> g;

int main() {
    int n, m, x, y;
    cin >> n >> m;

    for(int i=0; i<m; i++) {
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }

    vector<bool> visited(n+1, false);
    vector<int> prev(n+1);
    vector<int> dist(n+1, 1e9);
    dist[n] = 0;
    bool allVisited = false;

    while(!allVisited) {
        // picking vertex with minimum dist from source
        int mini = 1e9, ind = -1;
        for(int i=1; i<=n; i++) {
            if(dist[i]  < mini && visited[i] == false) {
                ind = i;
                mini = dist[i];
            }

        }
        if(ind == -1) {
            allVisited = true;
        }
        else {
            visited[ind] = true;
            for(int i: g[ind]) {
                if(dist[i] > dist[ind] + 1) {
                    dist[i] = dist[ind]+1;
                    prev[i] = ind;
                }
            }
        }
    }
    if(dist[1] == 1e9) {
        cout << "IMPOSSIBLE";
    }
    else {
        cout << dist[1]+1 << endl;
        int i=1;
        while(i != n) {
            cout << i << " ";
            i = prev[i];
        }
        cout << n;
    }
}
