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
const int N = 2e4, M = 1'000'000'007, OO = 0X3F3F3F3F3F3F3F3F;
const double EPS = 1e-9, pi = 3.141592653589793;
#define kill return 0
typedef vector<int> vi;
typedef vector<vi> vvi;
#define pb push_back
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
 
template<typename A, typename B>
istream &operator>>(istream &fin, pair<A, B> &p) {
    fin >> p.X >> p.Y;
    return fin;
}
 
template<typename A, typename B>
std::ostream &operator<<(std::ostream &fout, const std::pair<A, B> &p) {
    fout << p.first << " " << p.second;
    return fout;
}
 
enum dir { d, r, u, l, ul, dr, ur, dl };
 
int dx[8] = {1, 0, -1, 0, -1, 1, -1, 1};
int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};
 
 
void preprocessing() {
}
 
auto Solve(const int n, const int m) {
 
    vector<int> v(n), bit(n + 1);
    auto get = [&](int i) {
        int res = 0;
        for (++i; i; i -= (i & -i)) {
            res += bit[i - 1];
        }
        return res;
    };
    auto add = [&](int i, int val) {
        for (++i; i <= n; i += (i & -i)) {
            bit[i - 1] += val;
        }
    };
    auto getRange = [&](int s, int e) {
        return get(e) - get(s - 1);
    };
    auto getVal = [&](int i) {
        return getRange(i , i);
    };
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    // cout << v << endl;
    vector<int> ans;
    for (int i = 0; i < m; ++i) {
        int ty, s, e , x;
        cin >> ty;
        if (ty == 1) {
            cin >>  s >> e >> x;
            add(-- s , x) ;
            add(-- e + 1 , -x) ;
        }else {
            cin >> x ;x--;
            ans.pb( v[x] + get(x));
        }
    }
    return ans;
 
}
 
bool solve_test(const int test_number) {
    int n, m;
    if (!(cin >> n >> m))
        return false;
    auto ans = Solve(n, m);
    // cout << ans << endl;
    for (auto it: ans) cout << it << endl;
    return true;
}
 
void Stress() {
    // for (int n = 2; n <= 1; ++n)
    //     cerr << n << ' ' << Solve(n) << '\n';
}
 
int32_t main() {
    Zied();
    Stress();
    preprocessing();
    int test_cases = 1;
    // cin >> test_cases;
    for (int tc = 1; tc <= test_cases; tc++) {
        // cout << "Case " << tc << ": " << endl;
        if (!solve_test(tc))break;
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