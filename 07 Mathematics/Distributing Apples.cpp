#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
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
#define sub_mod(a, b) ((((a % M) - (b % M)) % M + M) % M)
const int N = 1e5 + 5, M = 1000000007, OO = 0X3F3F3F3F3F3F3F3F;
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
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
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
 
const int MOD = 1e9 + 7;
 
struct mint {
    int value;
 
    mint(int v = 0) {
        value = v % MOD;
        if (value < 0) value += MOD;
    }
 
    mint(int a, int b) : value(0) {
        *this += a;
        *this /= b;
    }
 
    mint &operator+=(mint const &b) {
        value += b.value;
        if (value >= MOD) value -= MOD;
        return *this;
    }
 
    mint &operator-=(mint const &b) {
        value -= b.value;
        if (value < 0) value += MOD;
        return *this;
    }
 
    mint &operator*=(mint const &b) {
        value = 1ll * value * b.value % MOD;
        return *this;
    }
 
    friend mint power(mint a, ll e) {
        mint res = 1;
        while (e) {
            if (e & 1) res *= a;
            a *= a;
            e >>= 1;
        }
        return res;
    }
 
    friend mint inv(mint a) { return power(a, MOD - 2); }
 
    mint &operator/=(mint const &b) { return *this *= inv(b); }
    friend mint operator+(mint a, mint const b) { return a += b; }
    friend mint operator-(mint a, mint const b) { return a -= b; }
    friend mint operator-(mint const a) { return 0 - a; }
    friend mint operator*(mint a, mint const b) { return a *= b; }
    friend mint operator/(mint a, mint const b) { return a /= b; }
    friend ostream &operator<<(ostream &os, mint const &a) { return os << a.value; }
    friend bool operator==(mint const &a, mint const &b) { return a.value == b.value; }
    friend bool operator!=(mint const &a, mint const &b) { return a.value != b.value; }
};
 
struct Comb {
    vector<mint> fact, invr;
 
    Comb(int n) {
        fact.assign(n + 5, 1);
        invr.assign(n + 5, 1);
        for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i, invr[i] = inv(fact[i]);
    }
 
    mint nPr(int n, int r) {
        return n < r ? 0 : fact[n] * invr[n - r];
    }
 
    mint nCr(int n, int r) {
        return nPr(n, r) * invr[r];
    }
 
    mint SAndBars(int n, int k) {
        if (n < 0) return 0;
        return nCr(n + k - 1, k - 1);
    }
};
 
auto Solve(const int &n) {
    int m;
    cin >> m;
    Comb comb(n + m + 5);
    return comb.SAndBars(m, n);
}
 
 
bool solve_test(const int test_number) {
    int n;
    if (!(cin >> n))
        return false;
    // Solve(n);
    auto ans = Solve(n);
    cout << ans << endl;
    // for (auto &it: ans) cout << it << '\n';
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