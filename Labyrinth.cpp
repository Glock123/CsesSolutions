#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#define mp make_pair

using namespace std;

/**

*/

vector<pair<int, vector<char>>> all;
int n, m;

void rec(vector<vector<char>>& a, vector<char>& curr, vector<vector<bool>>& visited, int dist, int i, int j) {
    if(a[i][j] == 'B') {
        all.push_back({dist, curr});
        return;
    }
    //cout << "IN rec\n";
    visited[i][j] = true;
    if(j+1 < m && visited[i][j+1] == false && (a[i][j+1] == '.' || a[i][j+1] == 'B')) {
        curr.push_back('R');
        rec(a, curr, visited, dist+1, i, j+1);
        curr.pop_back();

    }
    if(j-1 >= 0 && visited[i][j-1] == false && (a[i][j-1] == '.' || a[i][j-1] == 'B')) {
        curr.push_back('L');
        rec(a, curr, visited, dist+1, i, j-1);
        curr.pop_back();

    }

    if(i+1 < n && visited[i+1][j] == false && (a[i+1][j] == '.' || a[i+1][j] == 'B')) {
        curr.push_back('D');
        rec(a, curr, visited, dist+1, i+1, j);
        curr.pop_back();

    }
    if(i-1 >= 0 && visited[i-1][j] == false && (a[i-1][j] == '.' || a[i-1][j] == 'B')) {
        curr.push_back('U');
        rec(a, curr, visited, dist+1, i-1, j);
        curr.pop_back();

    }

    return;
}

int main() {
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    pair<int, int> start;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> a[i][j];
            if(a[i][j] == 'A') start = mp(i, j);
        }
    }
    vector<char> curr;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    rec(a, curr, visited, 0, start.first, start.second);

    if(all.size() == 0) return printf("NO") * 0;

    else {
        cout << "YES\n";
        sort(all.begin(), all.end());

        cout << all[0].first << endl;
        for(char c: all[0].second) cout << c;
    }
    cout << endl;
    for(auto i: all) {
        cout << i.first << " ";
        for(auto j: i.second) cout << j ;
        cout << endl;
    }
    return 0;
}
