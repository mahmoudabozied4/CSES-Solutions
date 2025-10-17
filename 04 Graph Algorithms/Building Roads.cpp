#include <bits/stdc++.h>
// علمكم الله ما ينفعكم و نفعكم بما تعلمتم و زادكم علما
// وَأَن لَّيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ، وَأَنَّ سَعْيَهُ سَوْفَ يُرَىٰ
using namespace std;
#define ll long long
#define int long long
#define ull unsigned long long
#define endl '\n'
typedef pair < int , int > pii;
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
const int N = 1e9 , M = 1e9 + 7 , OO = 0X3F3F3F3F3F3F3F3F;
const double EPS = 1e-9 , pi = 3.141592653589793;
#define kill return 0
vector < string > RET = {"NO", "YES"};
#define IO(NAME) \
cin.tie(0)->sync_with_stdio(0); \
if(fopen(NAME ".in","r")) freopen(NAME ".in","r",stdin), \
freopen(NAME ".out","w",stdout);
 
void Zied(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}
 
template <typename T = int>
istream& operator >>(istream& in, vector < T >& v){
    for ( auto& x : v ) in >> x;
    return in;
}
 
template <typename T = int>
ostream& operator <<(ostream& out, const vector < T >& v){
    for ( const T& x : v ) out << x << ' ';
    return out;
}
 
int dx[] = {+0, +0, -1, +1, +1, +1, -1, -1};
int dy[] = {-1, +1, +0, +0, +1, -1, +1, -1};
char di[] = {'D', 'L', 'U', 'R'};
 
void preprocessing(){
}
 
void Solve(){
    int n , m;
    cin >> n >> m;
    vector < vector < int > > grid(n, vector < int >());
    for ( int i = 0 ; i < m ; i++ ){
        int u , v;
        cin >> u >> v;
        u--, v--;
        grid[u].push_back(v);
        grid[v].push_back(u);
    }
    vector < int > v;
    vector < bool > vis(n);
    function < void(int) > dfs = [&](int u){
        vis[u] = 1;
        for ( auto v : grid[u] ){
            if ( !vis[v] ){
                dfs(v);
            }
        }
    };\
 
    int cnt = 0;
    for ( int i = 0 ; i < n ; ++i ){
        if ( !vis[i] ){
            cnt++;
            v.push_back(i);
            dfs(i);
        }
    }
    if ( cnt ){
        cout << cnt - 1 << endl;
        for ( int i = 1 ; i < sz(v) ; ++i ){
            cout << v[0] + 1 << " " << v[i] + 1 << endl;
        }
    }else{
        cout << 0 << endl;
    }
}
 
 
int32_t main(){
    Zied();
    preprocessing();
    int test_cases = 1;
    // cin >> test_cases;
    for ( int tc = 1 ; tc <= test_cases ; tc++ ){
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