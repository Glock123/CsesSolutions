#include <iostream>
#include <vector>

using namespace std;

int n, m;

void dfs(vector<vector<char>>& a, vector<vector<bool>>& visited, int i, int j) {
    visited[i][j] = true;
    if(i+1 < n && a[i+1][j] == '.' && visited[i+1][j] == false)
        dfs(a, visited, i+1, j);
    if(i-1 >= 0 && a[i-1][j] == '.' && visited[i-1][j] == false)
        dfs(a, visited, i-1, j);
    if(j+1 < m && a[i][j+1] == '.' && visited[i][j+1] == false)
        dfs(a, visited, i, j+1);
    if(j-1 >= 0 && a[i][j-1] == '.' && visited[i][j-1] == false)
        dfs(a, visited, i, j-1);
    return ;
}

int main() {
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin >> a[i][j];
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    int numRooms = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(visited[i][j] == false) {
                if(a[i][j] == '.') {
                    dfs(a, visited, i, j);
                    numRooms++;
                }
                else visited[i][j] = true;
            }
        }
    }
    cout << numRooms;
}
