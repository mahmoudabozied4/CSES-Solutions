#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define fi first
#define se second
#define Zied ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
 
const int N = 2e5 + 10;
const int inf = 2e9;
const int mod = 1e9 + 7;
const int Mod = 998244353;
 
int c[26];
void solve() {
    string s, ans = "";
    cin >> s;
    char last, cur;
    int mx, k, len, n;
    len = n = s.size();
    cin >> s;
    for(int i = 0; i < len; i++) {
        c[s[i] - 'A']++;
    }
    for(int p = 0; p < len; p++) {
        mx = 0;
        k = 0;
        cur = '#';
        for(int i = 0; i < 26; i++) {
            if(c[i] > k) {
                k = c[i];
                mx = i;
            }
        }
        for(int i = 0; i < 26; i++) {
            if(c[i] == 0 || char(i + 'A') == last) continue;
            if((k - (i == mx)) * 2 <= n) {
                cur = char(i + 'A');
                c[i]--;
                n--;
                break;
            }
        }
        if(cur == '#') {
            cout << "-1";
            return;
        }
        ans += cur;
        last = cur;
    }
    cout << ans;
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