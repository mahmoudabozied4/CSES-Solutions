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
 
 
void preprocessing() {
}
 
struct det {
    int dist;  // Distance to vertex
    int cnt;   // Count of shortest paths
    int mn;    // Minimum number of edges in shortest path
    int mx;    // Maximum number of edges in shortest path
};
 
void Solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pii> > grid(n, vector<pii>());
 
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        grid[u].push_back({v, w});
    }
 
    auto dijkstra = [&]() {
        vector<det> dd(n);
        for (int i = 0; i < n; i++) {
            dd[i] = {OO, 0, OO, OO};
        }
 
        priority_queue<pii, vector<pii>, greater<> > q;
        dd[0] = {0, 1, 0, 0};
        q.emplace(0, 0);
 
        while (!q.empty()) {
            auto [d, u] = q.top();
            q.pop();
            if (dd[u].dist != d) continue;
 
            for (auto v: grid[u]) {
                int nd = dd[u].dist + v.Y;
                if (nd < dd[v.X].dist) {
                    // Found better path
                    dd[v.X] = {nd, dd[u].cnt, dd[u].mn + 1, dd[u].mx + 1};
                    q.emplace(nd, v.X);
                } else if (nd == dd[v.X].dist) {
                    // Equal Path
                    dd[v.X].cnt = add_mod(dd[v.X].cnt, dd[u].cnt);
                    dd[v.X].mn = min(dd[v.X].mn, dd[u].mn + 1);
                    dd[v.X].mx = max(dd[v.X].mx, dd[u].mx + 1);
                }
            }
        }
 
        cout << dd[n - 1].dist << " " << dd[n - 1].cnt << " "
                << dd[n - 1].mn << " " << dd[n - 1].mx << endl;
    };
 
    dijkstra();
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
 