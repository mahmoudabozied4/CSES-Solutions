#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

char mex(string adj){
    if (!std::count(adj.begin(), adj.end(),'A')) return 'A';
    if (!std::count(adj.begin(), adj.end(),'B')) return 'B';
    if (!std::count(adj.begin(), adj.end(),'C')) return 'C';
    if (!std::count(adj.begin(), adj.end(),'D')) return 'D';
    return 'E';
}
 

void solve() {
    int n, m;   
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
 
    auto get = [&](int r, int c){
        if (r < 0 || r >= n || c < 0 || c >= m) return ' ';
        return a[r][c];
    };
 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            string adj;
            adj += get(i, j);
            adj += get(i - 1, j);
            adj += get(i, j - 1);
            a[i][j] = mex(adj);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    
    return 0;
}

    