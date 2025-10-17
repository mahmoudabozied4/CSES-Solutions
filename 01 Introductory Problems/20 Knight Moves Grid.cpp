#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};
 
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> res(n, vector<int>(n, -1));
    queue<pair<int,int>> q;
 
    q.push({0, 0});
    res[0][0] = 0;
 
    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
 
        for(int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < n && ny < n && res[nx][ny] == -1) {
                res[nx][ny] = res[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}