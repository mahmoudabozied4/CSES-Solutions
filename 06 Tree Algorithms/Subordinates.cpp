#include <bits/stdc++.h>
// علمكم الله ما ينفعكم و نفعكم بما تعلمتم و زادكم علما
// وَأَن لَّيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ، وَأَنَّ سَعْيَهُ سَوْفَ يُرَىٰ
using namespace std;
#define ll long long
#define int long long
#define ull unsigned long long
#define endl '\n'
typedef pair<int, int> pii;
#define elif else if
#define endd(s) return void(cout << s << "\n")
#define Ceil(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
#define X first
#define Y second
#define fixed(n) fixed << setprecision(n)
#define sz(s) int32_t(s.size())
#define dbg(x) cout << #x << ": " << (x) << "\n";
#define getline(s) getline(cin >> ws, s)
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << "\n";
#define all(vec) vec.begin(), vec.end()
#define rall(v) v.rbegin(),v.rend()
#define mul_mod(a, b) (((a % M) * (b % M)) % M)
#define add_mod(a, b) (((a % M) + (b % M)) % M)
const int N = 2e4, M = 1e9 + 7, OO = 0X3F3F3F3F3F3F3F3F;
const double EPS = 1e-9, pi = 3.141592653589793;
#define kill return 0
vector<string> RET = {"NO", "YES"};
#define IO(NAME) \
cin.tie(0)->sync_with_stdio(0); \
if(fopen(NAME ".in","r")) freopen(NAME ".in","r",stdin), \
freopen(NAME ".out","w",stdout);
 
void Zied() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}
 
template<typename T = int>
istream &operator >>(istream &in, vector<T> &v) {
    for (auto &x: v) in >> x;
    return in;
}
 
template<typename T = int>
ostream &operator <<(ostream &out, const vector<T> &v) {
    for (const T &x: v) out << x << ' ';
    return out;
}
 
enum dir { d, r, u, l, ul, dr, ur, dl };
 
int dx[8] = {1, 0, -1, 0, -1, 1, -1, 1};
int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};
struct DSU {
    int n;
    int cnt;
    int maxi;
    vector<int> parent, size, mx;
 
    DSU(int sz) {
        n = sz;
        cnt = 0;
        maxi = 0 ;
        parent.resize(n + 1);
        size.resize(n + 1);
        mx.resize(n + 1);
        init();
    }
 
    void init() {
        for (int u = 1; u <= n; ++u)
            makeSet(u);
    }
 
    void makeSet(int u) {
        if (!size[u]) cnt++;
        parent[u] = u;
        size[u] = 1;
        mx[u] = u;
    }
 
 
    int find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]); // Path Compression
    }
 
    bool merge(int u, int v) {
        int uP = find(u), vP = find(v);
        if (vP == uP) return false ; // Cycle Detection
        if (size[vP] > size[uP]) swap(uP, vP);
        size[uP] += size[vP];
        maxi = max(maxi, size[uP]);
        mx[uP] = max(mx[uP], mx[vP]);
        parent[vP] = uP;
        cnt--;
        return true;
    }
};
 
 
void preprocessing() {
 
}
 
 
 
void Solve() {
    int n; cin >> n;
 
    vector<vector<int>> grid(n, vector<int>());
 
    for (int i = 1; i < n; ++i) {
        int x ; cin >> x; x--;
        grid[i].push_back(x);
        grid[x].push_back(i);
    }
 
    vector<bool> vis(n);
    vector<int> dp(n);
 
    function<void(int)> dfs = [&](int u){
        vis[u] = true;
        for (int v : grid[u]) {
            if (!vis[v]) {
                dfs(v);
                dp[u] += dp[v] + 1;
            }
        }
    };
dfs(0);
 
    for (int i = 0; i < n; ++i) {
        cout << dp[i] << " ";
    }
}
 
 
int32_t main() {
    Zied();
    preprocessing();
    int test_cases = 1;
    // cin >> test_cases;
    for (int tc = 1; tc <= test_cases; tc++) {
        //        cout << "Case #" << tc << ": ";
        Solve();
        //                cout << endl;
    }
    kill;
    //    Time
}
 
/*
              ,   .-'"'=;_  ,
              |\.'-~`-.`-`;/|
              \.` '.'~-.` './
              (\`,__=-'__,'/)
           _.-'-.( d\_/b ).-'-._
         /'.-'   ' .---. '   '-.`\
       /'  .' (=    (_)    =) '.  `\
      /'  .',  `-.__.-.__.-'  ,'.  `\
     (     .'.   V       V  ; '.     )
     (    |::  `-,__.-.__,-'  ::|    )
     |   /|`:.               .:'|\   |
     |  / | `:.              :' |`\  |
     | |  (  :.             .:  )  | |
     | |   ( `:.            :' )   | |
     | |    \ :.           .: /    | |
     | |     \`:.         .:'/     | |
     ) (      `\`:.     .:'/'      ) (
     (  `)_     ) `:._.:' (     _(`  )
     \  ' _)  .'           `.  (_ `  /
      \  '_) /   .'"```"'.   \ (_`  /
       `'"`  \  (         )  /  `"'`
   ___   MZ   `.`.       .'.'        ___
 .`   ``"""'''--`_)     (_'--'''"""``   `.
(_(_(___...--'"'`         `'"'--...___)_)_)
*/