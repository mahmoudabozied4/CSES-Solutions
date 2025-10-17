#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define fi first
#define se second
#define Zied ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
 
const int N = 10;
const int inf = 2e9;
const int mod = 1e9 + 7;
const int mod1 = 998244353;
 
int res;
bool us[N][N];
string s;
 
void rec(int x, int y, int k) {
    us[x][y] = 1;
    if(x == 1 && y == 7) {
        res += (k == 48);
        us[x][y] = 0;
        return;
    }
    if(us[x - 1][y] && us[x + 1][y] && !us[x][y + 1] && !us[x][y - 1]) {
        us[x][y] = 0;
        return;
    }
    if(!us[x - 1][y] && !us[x + 1][y] && us[x][y + 1] && us[x][y - 1]) {
        us[x][y] = 0;
        return;
    }
    if((s[k] == 'R' || s[k] == '?') && !us[x + 1][y]) {
        rec(x + 1, y, k + 1);
    }
    if((s[k] == 'L' || s[k] == '?') && !us[x - 1][y]) {
        rec(x - 1, y, k + 1);
    }
    if((s[k] == 'U' || s[k] == '?') && !us[x][y - 1]) {
        rec(x, y - 1, k + 1);
    }
    if((s[k] == 'D' || s[k] == '?') && !us[x][y + 1]) {
        rec(x, y + 1, k + 1);
    }
    us[x][y] = 0;
}
 
void solve() {
    cin >> s;
    for(int i = 0; i <= 8; i++) {
        us[0][i] = 1;
        us[i][0] = 1;
        us[8][i] = 1;
        us[i][8] = 1;
    }
    rec(1, 1, 0);
    cout << res;
}
 
int main() {
    Zied;
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
        cout << "\n";
    }
    return 0;
}